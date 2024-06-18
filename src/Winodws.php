<?php

/**
 * php-gui (http://toknot.com)
 *
 * @copyright  Copyright (c) 2024 Szopen Xiao (Toknot.com)
 * @license    http://toknot.com/LICENSE.txt New BSD License
 * @link       https://github.com/chopins/php-gui
 *
 */

namespace Toknot\Gui;

class Windows
{
    const SW_HIDE = 0;
    const SW_SHOWNORMAL = 1;
    const SW_NORMAL = 1;
    const SW_SHOWMINIMIZED = 2;
    const SW_SHOWMAXIMIZED = 3;
    const SW_MAXIMIZE = 3;
    const SW_SHOWNOACTIVATE = 4;
    const SW_SHOW = 5;
    const SW_MINIMIZE = 6;
    const SW_SHOWMINNOACTIVE = 7;
    const SW_SHOWNA = 8;
    const SW_RESTORE = 9;
    const SW_SHOWDEFAULT = 10;
    const SW_FORCEMINIMIZE = 11;
    const SW_MAX = 11;
    const GCLP_HICON = -14;
    const GCLP_HICONSM = -34;

    const WS_OVERLAPPED = 0x00000000;
    const WS_CAPTION = 0x00C00000;
    const WS_SYSMENU = 0x00080000;
    const WS_MINIMIZEBOX = 0x00020000;
    const WS_MAXIMIZEBOX = 0x00010000;
    const WS_THICKFRAME = 0x00040000;
    const WS_OVERLAPPEDWINDOW = (self::WS_OVERLAPPED | self::WS_CAPTION | self::WS_SYSMENU | self::WS_THICKFRAME | self::WS_MINIMIZEBOX | self::WS_MAXIMIZEBOX);
    const WS_VISIBLE = 0x10000000;
    const WS_CHILD = 0x40000000;
    protected $cffi;

    public function __construct($cffi)
    {
        $this->cffi = $cffi;
    }

    protected function windowsCreateControl($dwExStyle, $type, $text, $dwStyle)
    {
        return $this->cffi->CreateWindowExW(
            $dwExStyle,
            $type,
            $text,
            $dwStyle | self::WS_CHILD | self::WS_VISIBLE,
            0,
            0,
            100,
            100,
            $utilWindow,
            NULL,
            $hInstance,
            $lpParam
        );
    }
}
