-- phpMyAdmin SQL Dump
-- version 4.5.4.1
-- http://www.phpmyadmin.net
--
-- Client :  localhost
-- Généré le :  Dim 01 Décembre 2019 à 22:23
-- Version du serveur :  5.7.11
-- Version de PHP :  7.2.7

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `mysql`
--

-- --------------------------------------------------------

--
-- Structure de la table `reservoir`
--

CREATE TABLE `reservoir` (
  `idReservoir_Reservoir` int(10) UNSIGNED NOT NULL,
  `marqueReservoir_Reservoir` text,
  `typeReservoir_Reservoir` text,
  `capaciteReservoir_Reservoir` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Contenu de la table `reservoir`
--

INSERT INTO `reservoir` (`idReservoir_Reservoir`, `marqueReservoir_Reservoir`, `typeReservoir_Reservoir`, `capaciteReservoir_Reservoir`) VALUES
(111, 'vetus', 'eau', 500),
(112, 'eval', 'essence', 1000),
(113, 'plastimo', 'eau', 100),
(114, 'emiliana serbatoi', 'essence', 2000);

--
-- Index pour les tables exportées
--

--
-- Index pour la table `reservoir`
--
ALTER TABLE `reservoir`
  ADD PRIMARY KEY (`idReservoir_Reservoir`);

--
-- AUTO_INCREMENT pour les tables exportées
--

--
-- AUTO_INCREMENT pour la table `reservoir`
--
ALTER TABLE `reservoir`
  MODIFY `idReservoir_Reservoir` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=115;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
