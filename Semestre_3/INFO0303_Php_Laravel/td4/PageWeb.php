<?php
class PageWeb{
    private static $onlineScripts=array();
    private static $scripts=array();
    public static function entete($titre){
        echo <<<HTML 
        //page html basic
        <div>$titre</div>
        HTML;

    }
    public static function addOnlineScript($code){
        PageWeb::$onlineScript()=$script;
    }
    ...
}