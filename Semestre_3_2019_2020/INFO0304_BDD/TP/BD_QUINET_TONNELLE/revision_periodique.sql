-- phpMyAdmin SQL Dump
-- version 4.5.4.1
-- http://www.phpmyadmin.net
--
-- Client :  localhost
-- Généré le :  Dim 01 Décembre 2019 à 22:24
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
-- Structure de la table `revision_periodique`
--

CREATE TABLE `revision_periodique` (
  `IdRevi_Revision_Periodique` int(10) UNSIGNED NOT NULL,
  `date_Revision_Periodique` int(11) DEFAULT NULL,
  `kilometrage_Revision_Periodique` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Contenu de la table `revision_periodique`
--

INSERT INTO `revision_periodique` (`IdRevi_Revision_Periodique`, `date_Revision_Periodique`, `kilometrage_Revision_Periodique`) VALUES
(11, 21220, 2000),
(12, 50620, 5000),
(13, 30721, 500),
(14, 150822, 1000);

--
-- Index pour les tables exportées
--

--
-- Index pour la table `revision_periodique`
--
ALTER TABLE `revision_periodique`
  ADD PRIMARY KEY (`IdRevi_Revision_Periodique`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
