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
-- Structure de la table `moteur`
--

CREATE TABLE `moteur` (
  `IdMoteur_Moteur` int(10) UNSIGNED NOT NULL,
  `nomMoteur_Moteur` text,
  `typeMoteur_Moteur` text,
  `pieceMoteur_Moteur` text,
  `marqueMoteur_Moteur` text,
  `capaMoteur_Moteur` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Contenu de la table `moteur`
--

INSERT INTO `moteur` (`IdMoteur_Moteur`, `nomMoteur_Moteur`, `typeMoteur_Moteur`, `pieceMoteur_Moteur`, `marqueMoteur_Moteur`, `capaMoteur_Moteur`) VALUES
(11111, 'guppy 2.5', 'hors-bord', 'alimentation, carburateur, helice, echappement, reservoir', 'selva', 3),
(11112, 'kta19ccec', 'in-bord', 'alimentation, carburateur, echappement, reservoir', 'Cummins', 500),
(11113, 'v8 xto offshore', 'hors-bord', 'alimentation, carburateur, helice, echappement, reservoir', 'yamaha', 425),
(11114, 'e-20', 'propulsion', 'alimentation, carburateur, helise, echappement', 'greenStar Marine', 20);

--
-- Index pour les tables exportées
--

--
-- Index pour la table `moteur`
--
ALTER TABLE `moteur`
  ADD PRIMARY KEY (`IdMoteur_Moteur`);

--
-- AUTO_INCREMENT pour les tables exportées
--

--
-- AUTO_INCREMENT pour la table `moteur`
--
ALTER TABLE `moteur`
  MODIFY `IdMoteur_Moteur` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11115;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
