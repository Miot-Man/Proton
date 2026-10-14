#include "unix_private.h"

#if 0
#pragma makedep unix
#endif

#include <unordered_map>

#ifdef __linux__
#include <X11/keysym.h>
#endif

#ifdef __linux__
static const uint32_t vk_to_xkeysym[0xFF] =
{
    0,            /* 0x0  Undefined */
    0,            /* VK_LBUTTON */
    0,            /* VK_RBUTTON */
    XK_Cancel,    /* VK_CANCEL */
    0,            /* VK_MBUTTON */
    0,            /* VK_XBUTTON1 */
    0,            /* VK_XBUTTON2 */
    0,            /* 0x07 Undefined */
    XK_BackSpace, /* VK_BACK */
    XK_Tab,       /* VK_TAB */
    0,            /* 0x0A-0x0B  Undefined */
    0,
    XK_Clear,  /* VK_CLEAR */
    XK_Return, /* VK_RETURN */
    0,         /* 0x0E-0x0F  Undefined */
    0,
    XK_Shift_L,     /* VK_SHIFT */
    XK_Control_L,   /* VK_CONTROL */
    XK_Alt_L,       /* VK_MENU */
    XK_Pause,       /* VK_PAUSE */
    XK_Caps_Lock,   /* VK_CAPITAL */
    0,              /* VK_KANA */
    0,              /* 0x16  Undefined */
    0,              /* VK_JUNJA */
    0,              /* VK_FINAL */
    0,              /* VK_HANJA */
    0,              /* 0x1A  Undefined */
    XK_Escape,      /* VK_ESCAPE */
    XK_Henkan_Mode, /* VK_CONVERT */
    XK_Muhenkan,    /* VK_NONCONVERT */
    0,              /* VK_ACCEPT */
    0,              /* VK_MODECHANGE */
    ' ',            /* VK_SPACE */
    XK_Prior,       /* VK_PRIOR */
    XK_Next,        /* VK_NEXT */
    XK_End,         /* VK_END */
    XK_Home,        /* VK_HOME */
    XK_Left,        /* VK_LEFT */
    XK_Up,          /* VK_UP */
    XK_Right,       /* VK_RIGHT */
    XK_Down,        /* VK_DOWN */
    XK_Select,      /* VK_SELECT */
    XK_Print,       /* VK_PRINT */
    XK_Execute,     /* VK_EXECUTE */
    XK_Print,       /* VK_SNAPSHOT */
    XK_Insert,      /* VK_INSERT */
    XK_Delete,      /* VK_DELETE */
    XK_Help,        /* VK_HELP */

    '0',
    '1',
    '2',
    '3',
    '4',
    '5',
    '6',
    '7',
    '8',
    '9',
    0,
    0,
    0,
    0,
    0,
    0,
    0, /* 0x3A-0x40  Undefined */
    'A',
    'B',
    'C',
    'D',
    'E',
    'F',
    'G',
    'H',
    'I',
    'J',
    'K',
    'L',
    'M',
    'N',
    'O',
    'P',
    'Q',
    'R',
    'S',
    'T',
    'U',
    'V',
    'W',
    'X',
    'Y',
    'Z',

    XK_Super_L,      /* VK_LWIN */
    XK_Super_R,      /* VK_RWIN */
    XK_Menu,         /* VK_APPS */
    0,               /* 0x5E  Unassigned */
    0,               /* VK_SLEEP */
    XK_KP_0,         /* VK_NUMPAD0 */
    XK_KP_1,         /* VK_NUMPAD1 */
    XK_KP_2,         /* VK_NUMPAD2 */
    XK_KP_3,         /* VK_NUMPAD3 */
    XK_KP_4,         /* VK_NUMPAD4 */
    XK_KP_5,         /* VK_NUMPAD5 */
    XK_KP_6,         /* VK_NUMPAD6 */
    XK_KP_7,         /* VK_NUMPAD7 */
    XK_KP_8,         /* VK_NUMPAD8 */
    XK_KP_9,         /* VK_NUMPAD9 */
    XK_KP_Multiply,  /* VK_MULTIPLY */
    XK_KP_Add,       /* VK_ADD */
    XK_KP_Separator, /* VK_SEPARATOR */
    XK_KP_Subtract,  /* VK_SUBTRACT */
    XK_KP_Decimal,   /* VK_DECIMAL */
    XK_KP_Divide,    /* VK_DIVIDE */
    XK_F1,           /* VK_F1 */
    XK_F2,           /* VK_F2 */
    XK_F3,           /* VK_F3 */
    XK_F4,           /* VK_F4 */
    XK_F5,           /* VK_F5 */
    XK_F6,           /* VK_F6 */
    XK_F7,           /* VK_F7 */
    XK_F8,           /* VK_F8 */
    XK_F9,           /* VK_F9 */
    XK_F10,          /* VK_F10 */
    XK_F11,          /* VK_F11 */
    XK_F12,          /* VK_F12 */
    XK_F13,          /* VK_F13 */
    XK_F14,          /* VK_F14 */
    XK_F15,          /* VK_F15 */
    XK_F16,          /* VK_F16 */
    XK_F17,          /* VK_F17 */
    XK_F18,          /* VK_F18 */
    XK_F19,          /* VK_F19 */
    XK_F20,          /* VK_F20 */
    XK_F21,          /* VK_F21 */
    XK_F22,          /* VK_F22 */
    XK_F23,          /* VK_F23 */
    XK_F24,          /* VK_F24 */
    0,               /* VK_NAVIGATION_VIEW */
    0,               /* VK_NAVIGATION_MENU */
    0,               /* VK_NAVIGATION_UP */
    0,               /* VK_NAVIGATION_DOWN */
    0,               /* VK_NAVIGATION_LEFT */
    0,               /* VK_NAVIGATION_RIGHT */
    0,               /* VK_NAVIGATION_ACCEPT */
    0,               /* VK_NAVIGATION_CANCEL */
    XK_Num_Lock,     /* VK_NUMLOCK */
    XK_Scroll_Lock,  /* VK_SCROLL */
    XK_KP_Equal,     /* VK_OEM_NEC_EQUAL */
    0,               /* VK_OEM_FJ_JISHO */
    0,               /* VK_OEM_FJ_MASSHOU */
    0,               /* VK_OEM_FJ_TOUROKU */
    0,               /* VK_OEM_FJ_LOYA */
    0,               /* VK_OEM_FJ_ROYA */
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,            /* 0x97-0x9F  Unassigned */
    XK_Shift_L,   /* VK_LSHIFT */
    XK_Shift_R,   /* VK_RSHIFT */
    XK_Control_L, /* VK_LCONTROL */
    XK_Control_R, /* VK_RCONTROL */
    XK_Alt_L,     /* VK_LMENU */
    XK_Alt_R,     /* VK_RMENU */

    /* below are OEM, browser keys, etc */
};

uint32_t manual_convert_nNativeKeyCode( uint32_t win_vk )
{
    if(win_vk < sizeof(vk_to_xkeysym) / sizeof(*vk_to_xkeysym))
        return vk_to_xkeysym[win_vk];
    return 0;
}
#elif defined(__APPLE__)
/* Windows VK -> macOS virtual key code (kVK_* from HIToolbox Events.h, inlined because
 * Carbon headers clash with Wine's), as CEF uses for native key codes.
 * Unmapped keys return ~0u rather than 0, which is kVK_ANSI_A. */
static const uint32_t vk_to_mac_keycode[0xFF] =
{
    [0x08] = 0x33, /* kVK_Delete */
    [0x09] = 0x30, /* kVK_Tab */
    [0x0D] = 0x24, /* kVK_Return */
    [0x10] = 0x38, /* kVK_Shift */
    [0x11] = 0x3B, /* kVK_Control */
    [0x12] = 0x3A, /* kVK_Option */
    [0x14] = 0x39, /* kVK_CapsLock */
    [0x1B] = 0x35, /* kVK_Escape */
    [0x20] = 0x31, /* kVK_Space */
    [0x21] = 0x74, /* kVK_PageUp */
    [0x22] = 0x79, /* kVK_PageDown */
    [0x23] = 0x77, /* kVK_End */
    [0x24] = 0x73, /* kVK_Home */
    [0x25] = 0x7B, /* kVK_LeftArrow */
    [0x26] = 0x7E, /* kVK_UpArrow */
    [0x27] = 0x7C, /* kVK_RightArrow */
    [0x28] = 0x7D, /* kVK_DownArrow */
    [0x2D] = 0x72, /* kVK_Help */
    [0x2E] = 0x75, /* kVK_ForwardDelete */
    [0x30] = 0x1D, /* kVK_ANSI_0 */
    [0x31] = 0x12, /* kVK_ANSI_1 */
    [0x32] = 0x13, /* kVK_ANSI_2 */
    [0x33] = 0x14, /* kVK_ANSI_3 */
    [0x34] = 0x15, /* kVK_ANSI_4 */
    [0x35] = 0x17, /* kVK_ANSI_5 */
    [0x36] = 0x16, /* kVK_ANSI_6 */
    [0x37] = 0x1A, /* kVK_ANSI_7 */
    [0x38] = 0x1C, /* kVK_ANSI_8 */
    [0x39] = 0x19, /* kVK_ANSI_9 */
    [0x41] = 0x00, /* kVK_ANSI_A */
    [0x42] = 0x0B, /* kVK_ANSI_B */
    [0x43] = 0x08, /* kVK_ANSI_C */
    [0x44] = 0x02, /* kVK_ANSI_D */
    [0x45] = 0x0E, /* kVK_ANSI_E */
    [0x46] = 0x03, /* kVK_ANSI_F */
    [0x47] = 0x05, /* kVK_ANSI_G */
    [0x48] = 0x04, /* kVK_ANSI_H */
    [0x49] = 0x22, /* kVK_ANSI_I */
    [0x4A] = 0x26, /* kVK_ANSI_J */
    [0x4B] = 0x28, /* kVK_ANSI_K */
    [0x4C] = 0x25, /* kVK_ANSI_L */
    [0x4D] = 0x2E, /* kVK_ANSI_M */
    [0x4E] = 0x2D, /* kVK_ANSI_N */
    [0x4F] = 0x1F, /* kVK_ANSI_O */
    [0x50] = 0x23, /* kVK_ANSI_P */
    [0x51] = 0x0C, /* kVK_ANSI_Q */
    [0x52] = 0x0F, /* kVK_ANSI_R */
    [0x53] = 0x01, /* kVK_ANSI_S */
    [0x54] = 0x11, /* kVK_ANSI_T */
    [0x55] = 0x20, /* kVK_ANSI_U */
    [0x56] = 0x09, /* kVK_ANSI_V */
    [0x57] = 0x0D, /* kVK_ANSI_W */
    [0x58] = 0x07, /* kVK_ANSI_X */
    [0x59] = 0x10, /* kVK_ANSI_Y */
    [0x5A] = 0x06, /* kVK_ANSI_Z */
    [0x5B] = 0x37, /* kVK_Command */
    [0x5C] = 0x36, /* kVK_RightCommand */
    [0x60] = 0x52, /* kVK_ANSI_Keypad0 */
    [0x61] = 0x53, /* kVK_ANSI_Keypad1 */
    [0x62] = 0x54, /* kVK_ANSI_Keypad2 */
    [0x63] = 0x55, /* kVK_ANSI_Keypad3 */
    [0x64] = 0x56, /* kVK_ANSI_Keypad4 */
    [0x65] = 0x57, /* kVK_ANSI_Keypad5 */
    [0x66] = 0x58, /* kVK_ANSI_Keypad6 */
    [0x67] = 0x59, /* kVK_ANSI_Keypad7 */
    [0x68] = 0x5B, /* kVK_ANSI_Keypad8 */
    [0x69] = 0x5C, /* kVK_ANSI_Keypad9 */
    [0x6A] = 0x43, /* kVK_ANSI_KeypadMultiply */
    [0x6B] = 0x45, /* kVK_ANSI_KeypadPlus */
    [0x6D] = 0x4E, /* kVK_ANSI_KeypadMinus */
    [0x6E] = 0x41, /* kVK_ANSI_KeypadDecimal */
    [0x6F] = 0x4B, /* kVK_ANSI_KeypadDivide */
    [0x70] = 0x7A, /* kVK_F1 */
    [0x71] = 0x78, /* kVK_F2 */
    [0x72] = 0x63, /* kVK_F3 */
    [0x73] = 0x76, /* kVK_F4 */
    [0x74] = 0x60, /* kVK_F5 */
    [0x75] = 0x61, /* kVK_F6 */
    [0x76] = 0x62, /* kVK_F7 */
    [0x77] = 0x64, /* kVK_F8 */
    [0x78] = 0x65, /* kVK_F9 */
    [0x79] = 0x6D, /* kVK_F10 */
    [0x7A] = 0x67, /* kVK_F11 */
    [0x7B] = 0x6F, /* kVK_F12 */
    [0x7C] = 0x69, /* kVK_F13 */
    [0x7D] = 0x6B, /* kVK_F14 */
    [0x7E] = 0x71, /* kVK_F15 */
    [0x7F] = 0x6A, /* kVK_F16 */
    [0x80] = 0x40, /* kVK_F17 */
    [0x81] = 0x4F, /* kVK_F18 */
    [0x82] = 0x50, /* kVK_F19 */
    [0x83] = 0x5A, /* kVK_F20 */
    [0xA0] = 0x38, /* kVK_Shift */
    [0xA1] = 0x3C, /* kVK_RightShift */
    [0xA2] = 0x3B, /* kVK_Control */
    [0xA3] = 0x3E, /* kVK_RightControl */
    [0xA4] = 0x3A, /* kVK_Option */
    [0xA5] = 0x3D, /* kVK_RightOption */
    [0xBA] = 0x29, /* kVK_ANSI_Semicolon */
    [0xBB] = 0x18, /* kVK_ANSI_Equal */
    [0xBC] = 0x2B, /* kVK_ANSI_Comma */
    [0xBD] = 0x1B, /* kVK_ANSI_Minus */
    [0xBE] = 0x2F, /* kVK_ANSI_Period */
    [0xBF] = 0x2C, /* kVK_ANSI_Slash */
    [0xC0] = 0x32, /* kVK_ANSI_Grave */
    [0xDB] = 0x21, /* kVK_ANSI_LeftBracket */
    [0xDC] = 0x2A, /* kVK_ANSI_Backslash */
    [0xDD] = 0x1E, /* kVK_ANSI_RightBracket */
    [0xDE] = 0x27, /* kVK_ANSI_Quote */
};

uint32_t manual_convert_nNativeKeyCode( uint32_t win_vk )
{
    if (win_vk < sizeof(vk_to_mac_keycode) / sizeof(*vk_to_mac_keycode) &&
        (vk_to_mac_keycode[win_vk] || win_vk == 0x41 /* VK_A -> kVK_ANSI_A == 0 */))
        return vk_to_mac_keycode[win_vk];
    return ~0u;
}
#else
#error You must implement VK<->Native keysym conversion for this platform.
#endif

typedef std::unordered_map< uint64_t, char * > glyph_cache;
static glyph_cache input_cache, input_cache_svg, input_cache_png, xbox_cache, controller_cache;

static const char *glyph_cache_lookup( glyph_cache &cache, const char *str, uint16_t origin,
                                       uint32_t flags, uint16_t size )
{
    uint64_t key = (uint64_t)flags << 32 | (uint64_t)size << 16 | origin;

    if (cache.find( key ) == cache.end())
    {
        char *dos_path = (char *)malloc( PATH_MAX );
        steamclient_unix_path_to_dos_path( 1, str, dos_path, PATH_MAX, 0 );
        cache[key] = dos_path;
    }

    return cache[key];
}

template< typename Iface, typename Params >
static NTSTATUS ISteamController_GetGlyphForActionOrigin( Iface *iface, Params *params, bool wow64 )
{
    if (!(params->_ret = iface->GetGlyphForActionOrigin( params->eOrigin ))) return 0;
    params->_ret = glyph_cache_lookup( controller_cache, params->_ret, params->eOrigin, 0, 0 );
    return 0;
}

template< typename Iface, typename Params >
static NTSTATUS ISteamController_GetGlyphForXboxOrigin( Iface *iface, Params *params, bool wow64 )
{
    if (!(params->_ret = iface->GetGlyphForXboxOrigin( params->eOrigin ))) return 0;
    params->_ret = glyph_cache_lookup( xbox_cache, params->_ret, params->eOrigin, 0, 0 );
    return 0;
}

template< typename Iface, typename Params >
static NTSTATUS ISteamInput_GetGlyphForActionOrigin( Iface *iface, Params *params, bool wow64 )
{
    if (!(params->_ret = iface->GetGlyphForActionOrigin( params->eOrigin ))) return 0;
    params->_ret = glyph_cache_lookup( input_cache, params->_ret, params->eOrigin, 0, 0 );
    return 0;
}

template< typename Iface, typename Params >
static NTSTATUS ISteamInput_GetGlyphForXboxOrigin( Iface *iface, Params *params, bool wow64 )
{
    if (!(params->_ret = iface->GetGlyphForXboxOrigin( params->eOrigin ))) return 0;
    params->_ret = glyph_cache_lookup( xbox_cache, params->_ret, params->eOrigin, 0, 0 );
    return 0;
}

static void (W_CDECL *w_EnableActionEventCallbacks_152)( SteamInputActionEvent_t * );
static void U_CDECL u_SteamInputActionEventCallbackPointer_152( SteamInputActionEvent_t *dat )
{
    if (w_EnableActionEventCallbacks_152) queue_cdecl_func_callback( (w_cdecl_func)w_EnableActionEventCallbacks_152, dat, sizeof(*dat) );
}

template< typename Iface, typename Params >
NTSTATUS ISteamInput_EnableActionEventCallbacks( Iface *iface, Params *params, bool wow64 )
{
    w_EnableActionEventCallbacks_152 = params->pCallback;
    iface->EnableActionEventCallbacks( params->pCallback ? &u_SteamInputActionEventCallbackPointer_152 : NULL );
    return 0;
}

template< typename Iface, typename Params >
static NTSTATUS ISteamInput_GetGlyphPNGForActionOrigin( Iface *iface, Params *params, bool wow64 )
{
    if (!(params->_ret = iface->GetGlyphPNGForActionOrigin( params->eOrigin, params->eSize, params->unFlags ))) return 0;
    params->_ret = glyph_cache_lookup( input_cache_png, params->_ret, params->eOrigin, params->unFlags, params->eSize );
    return 0;
}

template< typename Iface, typename Params >
static NTSTATUS ISteamInput_GetGlyphSVGForActionOrigin( Iface *iface, Params *params, bool wow64 )
{
    if (!(params->_ret = iface->GetGlyphSVGForActionOrigin( params->eOrigin, params->unFlags ))) return 0;
    params->_ret = glyph_cache_lookup( input_cache_svg, params->_ret, params->eOrigin, params->unFlags, 0 );
    return 0;
}

template< typename Iface, typename Params >
static NTSTATUS ISteamInput_GetGlyphForActionOrigin_Legacy( Iface *iface, Params *params, bool wow64 )
{
    if (!(params->_ret = iface->GetGlyphForActionOrigin_Legacy( params->eOrigin ))) return 0;
    params->_ret = glyph_cache_lookup( input_cache, params->_ret, params->eOrigin, 0, 0 );
    return 0;
}

LSTEAMCLIENT_UNIX_IMPL( ISteamController, SteamController005, GetGlyphForActionOrigin );

LSTEAMCLIENT_UNIX_IMPL( ISteamController, SteamController006, GetGlyphForActionOrigin );

LSTEAMCLIENT_UNIX_IMPL( ISteamController, SteamController007, GetGlyphForActionOrigin );
LSTEAMCLIENT_UNIX_IMPL( ISteamController, SteamController007, GetGlyphForXboxOrigin );

LSTEAMCLIENT_UNIX_IMPL( ISteamController, SteamController008, GetGlyphForActionOrigin );
LSTEAMCLIENT_UNIX_IMPL( ISteamController, SteamController008, GetGlyphForXboxOrigin );

LSTEAMCLIENT_UNIX_IMPL( ISteamInput, SteamInput001, GetGlyphForActionOrigin );
LSTEAMCLIENT_UNIX_IMPL( ISteamInput, SteamInput001, GetGlyphForXboxOrigin );

LSTEAMCLIENT_UNIX_IMPL( ISteamInput, SteamInput002, GetGlyphForActionOrigin );
LSTEAMCLIENT_UNIX_IMPL( ISteamInput, SteamInput002, GetGlyphForXboxOrigin );

LSTEAMCLIENT_UNIX_IMPL( ISteamInput, SteamInput005, EnableActionEventCallbacks );
LSTEAMCLIENT_UNIX_IMPL( ISteamInput, SteamInput005, GetGlyphPNGForActionOrigin );
LSTEAMCLIENT_UNIX_IMPL( ISteamInput, SteamInput005, GetGlyphSVGForActionOrigin );
LSTEAMCLIENT_UNIX_IMPL( ISteamInput, SteamInput005, GetGlyphForActionOrigin_Legacy );
LSTEAMCLIENT_UNIX_IMPL( ISteamInput, SteamInput005, GetGlyphForXboxOrigin );

LSTEAMCLIENT_UNIX_IMPL( ISteamInput, SteamInput006, EnableActionEventCallbacks );
LSTEAMCLIENT_UNIX_IMPL( ISteamInput, SteamInput006, GetGlyphPNGForActionOrigin );
LSTEAMCLIENT_UNIX_IMPL( ISteamInput, SteamInput006, GetGlyphSVGForActionOrigin );
LSTEAMCLIENT_UNIX_IMPL( ISteamInput, SteamInput006, GetGlyphForActionOrigin_Legacy );
LSTEAMCLIENT_UNIX_IMPL( ISteamInput, SteamInput006, GetGlyphForXboxOrigin );

LSTEAMCLIENT_UNIX_IMPL( ISteamInput, SteamInput007, EnableActionEventCallbacks );
LSTEAMCLIENT_UNIX_IMPL( ISteamInput, SteamInput007, GetGlyphPNGForActionOrigin );
LSTEAMCLIENT_UNIX_IMPL( ISteamInput, SteamInput007, GetGlyphSVGForActionOrigin );
LSTEAMCLIENT_UNIX_IMPL( ISteamInput, SteamInput007, GetGlyphForActionOrigin_Legacy );
LSTEAMCLIENT_UNIX_IMPL( ISteamInput, SteamInput007, GetGlyphForXboxOrigin );
