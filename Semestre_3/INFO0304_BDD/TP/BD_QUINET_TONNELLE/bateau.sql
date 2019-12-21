-- phpMyAdmin SQL Dump
-- version 4.5.4.1
-- http://www.phpmyadmin.net
--
-- Client :  localhost
-- Généré le :  Dim 01 Décembre 2019 à 22:20
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
-- Structure de la table `bateau`
--

CREATE TABLE `bateau` (
  `Immatriculation_Bateau` varchar(40) NOT NULL,
  `Nom_Bateau` text,
  `AnneeConstru_Bateau` int(11) DEFAULT NULL,
  `Marque_Bateau` text,
  `typeB` text,
  `Dimension_Bateau` text,
  `nbPlaces_Bateau` int(11) DEFAULT NULL,
  `poids_Bateau` int(11) DEFAULT NULL,
  `capaCarbu_Bateau` int(11) DEFAULT NULL,
  `capaEau_Bateau` int(11) DEFAULT NULL,
  `motorisation_Bateau` text
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Contenu de la table `bateau`
--

INSERT INTO `bateau` (`Immatriculation_Bateau`, `Nom_Bateau`, `AnneeConstru_Bateau`, `Marque_Bateau`, `typeB`, `Dimension_Bateau`, `nbPlaces_Bateau`, `poids_Bateau`, `capaCarbu_Bateau`, `capaEau_Bateau`, `motorisation_Bateau`) VALUES
('12AB12', 'MerryFisher', 2019, 'Jeanneau', 'Basique', '6.71x2.54m', 8, 1550, 200, 50, '1 moteur\r\n175 ch'),
('12CD56', 'Dolceriva', 2019, 'Riva', 'Hauturier', '14.92x4.26m', 10, 21400, 1000, 310, '2 moteur\r\n800 ch'),
('23BC23', 'La Recouvrance', 1990, 'Chantier du Guip', 'Hauturier', '41.60x6.40', 25, 130000, 2000, 1000, '1 moteur\r\n320 ch'),
('34AB98', 'Lucia 40', 2016, 'Fountaine Pajot', 'Hauturier', '11.73x6.63m', 8, 8900, 300, 530, '1 moteur\r\n2 ch');

--
-- Index pour les tables exportées
--

--
-- Index pour la table `bateau`
--
ALTER TABLE `bateau`
  ADD PRIMARY KEY (`Immatriculation_Bateau`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
