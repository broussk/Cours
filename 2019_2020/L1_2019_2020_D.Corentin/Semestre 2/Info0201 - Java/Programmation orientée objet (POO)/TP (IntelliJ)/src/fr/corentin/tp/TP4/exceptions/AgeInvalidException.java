package fr.corentin.tp.TP4.exceptions;

/**
 * Classe AgeInvalidException qui hérite de Exception.
 * @author DUPONT Corentin et LACROIX Owen
 * @version 13/02/2020
 */

public class AgeInvalidException extends Exception {
    /**
     * Constructeur par initilaisation.
     * @param msg le message de l'exception
     */
    public AgeInvalidException(String msg){
        super(msg);
    }



}
