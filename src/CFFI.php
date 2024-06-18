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

use RuntimeException;
use FFI;

class CFFI
{
    private static $ffi;
    private static $cffi;
    private $apiobj = '';
    private function __construct(string $gtklib = '')
    {
        if ($gtk) {
            $this->gtk($gtklib);
        } else {
            match (PHP_OS_FAMILY) {
                'Windows' => $this->windows(),
                'Darwin' => $this->darwin(),
                default => $this->gtk($gtklib),
            };
        }

    }

    public static function new()
    {
        if (self::$cffi) {
            return self::$cffi;
        }
        self::$cffi = new static;
        return self::$cffi;
    }

    private function loadHeader($file)
    {
        return file_get_contents(__DIR__ . "/include/$file");
    }

    public function __call($name, $arguments)
    {
        $arguments = array_values($arguments);
        return self::$ffi->$name(...$arguments);
    }
    public function __set($name, $value)
    {
        self::$ffi->$name = $value;
    }
    public function __get($name)
    {
        return self::$ffi->$name;
    }

    protected function windows()
    {
        $header = $this->loadHeader('windows.h');
        $lib = 'C:/Winodows/System32/User32.dll';
        if (self::is64bit()) {
            $type = 'typedef int64_t INT_PTR;typedef int64_t LONG_PTR;typedef uint64_t UINT_PTR;typedef uint64_t ULONG_PTR;';
        } else {
            $type = 'typedef int INT_PTR;typedef long LONG_PTR;typedef unsigned int UINT_PTR;typedef unsigned long ULONG_PTR;';
        }
        
        $this->define($header, 'WINAPI', '__stdcall');
        self::$ffi = FFI::cdef($type . $header, $lib);
        $this->apiobj = new Windows($this);
    }
    protected function define(&$cdef, $name, $value)
    {
        $cdef = preg_replace("/([\s\r\n\t,;{}()*]+)($name)([\s\r\n\t,;{}()*]+)/im", "$1$value$3", $cdef);
    }
    public function darwin()
    {
        $this->libname = 'darwin';
        throw new RuntimeException('Not implemented');
    }
    public function gtk(string $lib = '')
    {
        $env = getenv('LIBGTK_DLL_PATH');
        $header = $this->loadHeader('unix.h');
        $this->apiobj = new Gtk($this);
        if ($lib) {
            return self::$ffi = FFI::cdef($header, $lib);
        } else if (($lib = constant('LIBGTK_DLL_PATH'))) {
            return self::$ffi = FFI::cdef($header, $lib);
        } else if ($env) {
            return self::$ffi = FFI::cdef($header, $env);
        } else if (self::is64bit()) {
            $libs = glob('/usr/lib64/libgtk-3*');
        } else {
            $libs = glob('/usr/lib/libgtk-3*');
        }
        if (empty($libs)) {
            throw new RuntimeException('libgtk3 not found. set LIBGTK_DLL_PATH environment variable or define php constant LIBGTK_DLL_PATH, or pass path param to CFFI class at construct');
        }
        self::$ffi = FFI::cdef($header, $libs[0]);
    }

    public static function is64bit()
    {
        $fp = fopen(PHP_BINARY, 'rb');
        $magic0 = fread($fp, 2);
        if ($magic0 == 'MZ') {
            fseek($fp, 0x3c);
            $offset = unpack('v', fread($fp, 2))[1];
            fseek($fp, $offset + 4, SEEK_SET);
            $machine = unpack('v', fread($fp, 2))[1];
            $m32 = [0x184, 0x1c0, 0x14c, 0x6232, 0x5032];
            if (in_array($machine, $m32)) {
                return false;
            }
            fseek($fp, $offset + 24, SEEK_SET);
            $magic1 = unpack('v', fread($fp, 2))[1];
            return !($magic1 == 0x10b);
        }
        $magic0 .= fread($fp, 2);
        if ($magic0 == chr(0x7f) . 'ELF') {
            return fread($fp, 1) == 2;
        }
        return PHP_INT_SIZE == 8;
    }
}
