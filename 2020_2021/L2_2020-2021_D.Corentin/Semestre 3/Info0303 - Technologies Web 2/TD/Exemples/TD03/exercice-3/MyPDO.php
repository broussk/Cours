 <?php
final class MyPDO {

    private static $instance = null;

    private static $driverOptions = array(
        PDO::ATTR_ERRMODE            => PDO::ERRMODE_EXCEPTION,
        PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_ASSOC
    );
    
    /**
     * Get instance of the PDO.
     */
    public static function getInstance() : PDO {
        if(self::$instance === null)
            self::$instance = new PDO("mysql:host=".DB_HOST.";dbname=".DB_BASE.";charset=utf8", 
                                      DB_USER, DB_PASSWORD, self::$driverOptions);
        return self::$instance;
    }
    
}