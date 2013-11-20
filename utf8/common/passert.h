////////////////////////////////////////////////////////////////////////////////
//  Copyright(c) viticm@126.com
//
//  FileName    : passert.h
//  Version     : 1.0
//  Creator     : viticm
//  Create Date : 2013-11-20 12:12:49
//  Comment     : 断言控制器
//
////////////////////////////////////////////////////////////////////////////////
#ifndef PAP_COMMON_PASSERT_H_
#define PAP_COMMON_PASSERT_H_
extern int g_Command_Assert;//控制参数，不提示Assert的对话框，直接忽略
extern bool g_Command_IgnoreMessageBox;//控制参数，跳过MyMessageBox的中断
extern int g_FileNameFix;//文件名称后缀
extern int g_NeedManagerDoPosInit;//控制参数，是否需要初始化管理器数据


void __assert__(const char* file, unsigned int line, const char* func, const char* expr);
void __assertex__(const char* file, unsigned int line, const char* func, const char* expr, const char* msg);
void __assertspecial__(const char* file, unsigned int line, const char* func, const char* expr, const char* msg);
void __messagebox__(const char* msg);
void __protocol_assert__(const char* file, unsigned int line, const char* func, const char* expr);

#if defined(NDEBUG)
    #define Assert(expr) ((void)0)
    #define AssertEx(expr,msg) ((void)0)
    #define AssertSpecial(expr,msg) ((void)0)
    #define MyMessageBox(msg) ((void)0)
#elif defined(__LINUX__)
    #define Assert(expr) {if(!(expr)){__assert__(__FILE__,__LINE__,__PRETTY_FUNCTION__,#expr);}}
    #define ProtocolAssert(expr) ((void)((expr)?0:(__protocol_assert__(__FILE__,__LINE__,__PRETTY_FUNCTION__,#expr),0)))
    #define AssertEx(expr,msg) {if(!(expr)){__assertex__(__FILE__,__LINE__,__PRETTY_FUNCTION__,#expr,msg);}}
    #define AssertSpecial(expr,msg) {if(!(expr)){__assertspecial__(__FILE__,__LINE__,__PRETTY_FUNCTION__,#expr,msg);}}
    #define AssertExPass(expr,msg) {if(!(expr)){__assertex__(__FILE__,__LINE__,__PRETTY_FUNCTION__,#expr,msg);}}
    #define MyMessageBox(msg) ((void)0)
#elif defined(__WIN_CONSOLE__) || defined(__WIN32__) || defined(__WINDOWS__)
    #define Assert(expr) ((void)((expr)?0:(__assert__(__FILE__,__LINE__,__FUNCTION__,#expr),0)))
    #define AssertEx(expr,msg) ((void)((expr)?0:(__assertex__(__FILE__,__LINE__,__FUNCTION__,#expr,msg),0)))
    #define AssertSpecial(expr,msg) ((void)((expr)?0:(__assertspecial__(__FILE__,__LINE__,__FUNCTION__,#expr,msg),0)))
    #define MyMessageBox(msg) __messagebox__(msg)
#elif defined(__MFC__)
    #define Assert(expr) ASSERT(expr)
    #define AssertEx(expr,msg) ((void)0)
    #define AssertSpecial(expr,msg) ((void)0)
    #define MyMessageBox(msg) ((void)0)
#endif

//--------------------------------------------------------------------------------
// if nIndex was in [nFrom, nTo], this function will return TRUE. that means legal.
// If any illegal index found, this function will throw a except !!
// the szCodeLocation should be class_name::function_name, or something like this.
// Example: RangeCheckForIndex(i, 0, 10, "testclass::testfunction");
// Legal: 0<=i<=10;
// Illegal: i<0 or i>10;
//--------------------------------------------------------------------------------
bool RangeCheckForIndex_Assert(int index, int from, int to, char const* code_location);
#endif