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
-- Structure de la table `securite_obligatoire`
--

CREATE TABLE `securite_obligatoire` (
  `IdSecu_Securite_Obligatoire` int(10) UNSIGNED NOT NULL,
  `dureeVieMax_Securite_Obligatoire` int(11) DEFAULT NULL,
  `revisionPeriodique_Securite_Obligatoire` int(11) DEFAULT NULL,
  `nomObjet_Securite_Obligatoire` text,
  `typeBateau_Securite_Obligatoire` text,
  `Immatriculation_Bateau` varchar(40) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Contenu de la table `securite_obligatoire`
--

INSERT INTO `securite_obligatoire` (`IdSecu_Securite_Obligatoire`, `dureeVieMax_Securite_Obligatoire`, `revisionPeriodique_Securite_Obligatoire`, `nomObjet_Securite_Obligatoire`, `typeBateau_Securite_Obligatoire`, `Immatriculation_Bateau`) VALUES
(1, 291219, 40520, 'pile lampe', 'Basique', '12AB12'),
(2, 211234, 50221, 'radeau de survie', 'semi-hauturier', '12CD56'),
(3, 150729, 60620, 'gilet Sauvetage', 'basique', '23BC23'),
(4, 50639, 10720, 'extincteur', 'basique', '12AB12'),
(5, 212219, 50520, 'ligne de mouillage', 'basique', '12CD56');

--
-- Index pour les tables exportées
--

--
-- Index pour la table `securite_obligatoire`
--
ALTER TABLE `securite_obligatoire`
  ADD PRIMARY KEY (`IdSecu_Securite_Obligatoire`),
  ADD KEY `FK_Securite_Obligatoire_Immatriculation_Bateau` (`Immatriculation_Bateau`);

--
-- AUTO_INCREMENT pour les tables exportées
--

--
-- AUTO_INCREMENT pour la table `securite_obligatoire`
--
ALTER TABLE `securite_obligatoire`
  MODIFY `IdSecu_Securite_Obligatoire` int(10) UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;
--
-- Contraintes pour les tables exportées
--

--
-- Contraintes pour la table `securite_obligatoire`
--
ALTER TABLE `securite_obligatoire`
  ADD CONSTRAINT `FK_Securite_Obligatoire_Immatriculation_Bateau` FOREIGN KEY (`Immatriculation_Bateau`) REFERENCES `bateau` (`Immatriculation_Bateau`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
