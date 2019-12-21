-- phpMyAdmin SQL Dump
-- version 4.5.4.1
-- http://www.phpmyadmin.net
--
-- Client :  localhost
-- Généré le :  Dim 01 Décembre 2019 à 22:21
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
-- Structure de la table `entretien_courant`
--

CREATE TABLE `entretien_courant` (
  `IdEntre_Entretien_Courant` int(10) UNSIGNED NOT NULL,
  `RepPieceCassee` text,
  `changementPieceUsure` text
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Contenu de la table `entretien_courant`
--

INSERT INTO `entretien_courant` (`IdEntre_Entretien_Courant`, `RepPieceCassee`, `changementPieceUsure`) VALUES
(1111, 'filtre a eau moteur', 'a faire'),
(1112, 'filtre a essence moteur', 'urgent'),
(1113, 'sieges', 'non essentiel'),
(1114, 'joint moteur', 'urgent');

--
-- Index pour les tables exportées
--

--
-- Index pour la table `entretien_courant`
--
ALTER TABLE `entretien_courant`
  ADD PRIMARY KEY (`IdEntre_Entretien_Courant`);

--
-- AUTO_INCREMENT pour les tables exportées
--

--
-- AUTO_INCREMENT pour la table `entretien_courant`
--
ALTER TABLE `entretien_courant`
  MODIFY `IdEntre_Entretien_Courant` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=1115;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
