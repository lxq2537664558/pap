#ifndef PAP_CLIENT_LIB_CEGUI_EXTEND_FALAGARD_ATBOARD_PROPERTIES_H_
#define PAP_CLIENT_LIB_CEGUI_EXTEND_FALAGARD_ATBOARD_PROPERTIES_H_
#ifndef _FalChatBoardProperties_h_
#define _FalChatBoardProperties_h_

#include "CEGUIProperty.h"

// Start of CEGUI namespace section
namespace CEGUI
{
  /*!
  \brief
  Properties for the Falagard ChatBoard
  */
  namespace FalagardChatBoardProperties
  {
    /*!
    \brief
    Property to get/set chatboard kill timer

    \par Usage:
    - Name: KillTimer
    - Format: "[int]".

    */
    class KillTimer : public Property
    {
    public:
      KillTimer() : Property(
        "KillTimer",
        "Property to get/set ChatBoard KillTimer.",
        "")
      {}

      String   get(const PropertyReceiver* receiver) const;
      void   set(PropertyReceiver* receiver, const String& value);
    };
  }
}


#endif
#endif //PAP_CLIENT_LIB_CEGUI_EXTEND_FALAGARD_ATBOARD_PROPERTIES_H_
