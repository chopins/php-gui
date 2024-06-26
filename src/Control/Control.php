<?php

/**
 * php-gui (http://toknot.com)
 *
 * @copyright  Copyright (c) 2024 Szopen Xiao (Toknot.com)
 * @license    http://toknot.com/LICENSE.txt New BSD License
 * @link       https://github.com/chopins/php-gui
 *
 */

namespace Toknot\Gui\Control;

use Toknot\Gui\CFFI;

class Control
{
    protected $cffi;
    public function __construct($options = [], CFFI $cffi = null)
    {
        if (!$cffi) {
            $this->cffi = CFFI::new();
        }
    }
}
