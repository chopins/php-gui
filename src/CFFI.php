<?php

class CFFI
{
    private static $ffi;
    private static $cffi;
    private function __construct($gtk = false)
    {
        if ($gtk) {
            $this->gtk();
        } else {
            match (PHP_OS_FAMILY) {
                'Windows' => $this->windows(),
                'Darwin' => $this->darwin(),
                default => $this->gtk(),
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

    protected function windows()
    {
        $header = $this->loadHeader('windows.h');
        self::$ffi = FFI::cdef($header);
    }
    public function darwin()
    {
        throw new RuntimeException('Not implemented');
    }
    public function gtk()
    {
        $header = $this->loadHeader('unix.h');
        $libs = glob('/usr/lib/libgtk*');
        self::$ffi = FFI::cdef($header, $libs[0]);
    }

    public function is64bit()
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