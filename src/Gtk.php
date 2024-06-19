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

class Gtk
{
    protected $cffi;
    public function __construct(CFFI $cffi)
    {
        $this->cffi = $cffi;
    }
}
