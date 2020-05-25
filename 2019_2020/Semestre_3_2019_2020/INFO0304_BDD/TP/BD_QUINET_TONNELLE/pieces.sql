-- phpMyAdmin SQL Dump
-- version 4.5.4.1
-- http://www.phpmyadmin.net
--
-- Client :  localhost
-- Généré le :  Dim 01 Décembre 2019 à 22:22
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
-- Structure de la table `pieces`
--

CREATE TABLE `pieces` (
  `idPiece_Pieces` int(10) UNSIGNED NOT NULL,
  `marquePiece_Pieces` text,
  `nomPiece_Pieces` text
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Contenu de la table `pieces`
--

INSERT INTO `pieces` (`idPiece_Pieces`, `marquePiece_Pieces`, `nomPiece_Pieces`) VALUES
(201, 'salé diesel', 'helice'),
(202, 'wichard', 'poulie'),
(203, 'eval', 'filtre a essence'),
(204, 'reggiani nautica', 'joint');

--
-- Index pour les tables exportées
--

--
-- Index pour la table `pieces`
--
ALTER TABLE `pieces`
  ADD PRIMARY KEY (`idPiece_Pieces`);

--
-- AUTO_INCREMENT pour les tables exportées
--

--
-- AUTO_INCREMENT pour la table `pieces`
--
ALTER TABLE `pieces`
  MODIFY `idPiece_Pieces` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=205;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
