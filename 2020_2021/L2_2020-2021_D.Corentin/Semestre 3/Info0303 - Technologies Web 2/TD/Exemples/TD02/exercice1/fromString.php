<?php
    public static function fromString(string $ligne) : Actualite {
        $element = explode(";", $ligne);
        return new Actualite($element[0], $element[1], $element[2]);
    }