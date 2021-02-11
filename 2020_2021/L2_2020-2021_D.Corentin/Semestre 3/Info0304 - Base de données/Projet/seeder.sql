-- phpMyAdmin SQL Dump
-- version 4.5.4.1
-- http://www.phpmyadmin.net
--
-- Client :  localhost
-- Généré le :  Dim 06 Décembre 2020 à 13:55
-- Version du serveur :  5.7.11
-- Version de PHP :  7.2.7

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de données :  `fessetival`
--

-- --------------------------------------------------------

--
-- Structure de la table `artiste`
--

CREATE TABLE `artiste` (
  `IdArtiste` int(11) NOT NULL,
  `IntituléArtiste` varchar(100) DEFAULT NULL,
  `IdGroupe` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Contenu de la table `artiste`
--

INSERT INTO `artiste` (`IdArtiste`, `IntituléArtiste`, `IdGroupe`) VALUES
(0, 'Nicolas Patraque', 0),
(1, 'Manu Colomb', 0),
(2, 'Fabien La Loque', 0),
(3, 'Matt Buisson', 0),
(4, 'Will.u.R', 1),
(5, 'pas.de.apl', 1),
(6, 'ProFan', 1),
(7, 'Mike Chie-nada', 2),
(8, 'Bran Nelson', 2),
(9, 'Rob Guêpe', 2),
(10, 'Dave William', 2),
(11, 'Guy de Kriste', 3),
(12, 'Bangarang', 3),
(13, 'Angus Old', 4),
(14, 'Brian Johndad', 4),
(15, 'Stevie Old', 4),
(16, 'Phil Ipp', 4),
(17, 'Mountain william', 4),
(18, 'Orselane', 5),
(19, 'Greenje', 5),
(20, 'Syl20', 6),
(21, 'Bluem', 6),
(22, 'Hocu Luss', 6),
(23, 'Sublim Text', 6),
(24, 'Pierre Urbain', 6),
(25, 'Thom New', 7),
(26, 'Jonny blueIron', 7),
(27, 'Colin BlueIron', 7),
(28, 'Phil Segway', 7),
(29, 'Maitre Pims', 8),
(30, 'White J', 8),
(31, 'Maison Adams', 8),
(32, 'FaLé', 8),
(33, 'Skama', 8),
(34, 'Celine Fion', 9),
(35, 'Florantin Absciz', 10),
(36, 'Olivio Absciz', 10),
(37, 'Vlad', 11),
(38, 'Laurent Tryhard', 12),
(39, 'Dominique DelaCis', 12),
(40, 'Eric Feta', 12),
(41, 'Emile bordemer', 13),
(42, 'JeanLouis Pujadas', 13),
(43, 'Mario éLuigi', 13),
(44, 'Lorenzouille', 14),
(45, 'Bruno Juin', 15),
(46, 'James Charles', 16),
(47, 'Louis Chan', 16),
(48, 'Martin Krugger', 16),
(49, 'Vlad Imir', 16),
(50, 'Grimlin', 17),
(51, 'Chris Maroc', 17),
(52, 'Manu Evian', 17),
(53, 'Daniel GG', 17),
(54, 'Lance Rocket Letal', 18),
(55, 'Kurt Cubin', 19),
(56, 'Jesus Novo', 19),
(57, 'Eul gro Dave', 19),
(58, 'Jakouil', 20),
(59, 'Titou', 20),
(60, 'Germain', 20),
(61, 'Marleine', 20),
(62, 'Adan Lavigne', 21),
(63, 'Matthieu Flan', 21),
(64, 'Jamy Valentine', 21),
(65, 'Jessi Caramel', 21),
(66, 'Gowther', 22),
(67, 'Frasam', 22),
(68, 'DD', 22),
(69, 'Atom', 22),
(70, 'Boule', 23),
(71, 'Bill', 23),
(72, 'Georj Apel', 23),
(73, 'Goustaf', 23);

-- --------------------------------------------------------

--
-- Structure de la table `assister_à`
--

CREATE TABLE `assister_à` (
  `IdConcert` int(11) NOT NULL,
  `IdFestivalier` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Contenu de la table `assister_à`
--

INSERT INTO `assister_à` (`IdConcert`, `IdFestivalier`) VALUES
(0, 0);

-- --------------------------------------------------------

--
-- Structure de la table `batiment_ferme`
--

CREATE TABLE `batiment_ferme` (
  `IdBatimentF` int(11) NOT NULL,
  `TailleBatimentF` int(11) DEFAULT NULL,
  `IntutuleBaimentF` varchar(100) DEFAULT NULL,
  `IdTerrain` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `billet_d_entree`
--

CREATE TABLE `billet_d_entree` (
  `IdBillet` int(11) NOT NULL,
  `PrixBillet` decimal(7,2) DEFAULT NULL,
  `IDType` int(11) NOT NULL,
  `IdFestivalier` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Contenu de la table `billet_d_entree`
--

INSERT INTO `billet_d_entree` (`IdBillet`, `PrixBillet`, `IDType`, `IdFestivalier`) VALUES
(0, '80.00', 2, 0),
(1, '35.00', 0, 1),
(2, '35.00', 0, 2),
(3, '35.00', 0, 3),
(4, '80.00', 2, 4),
(5, '35.00', 0, 5),
(6, '80.00', 2, 6),
(7, '35.00', 0, 7),
(8, '60.00', 1, 8),
(9, '60.00', 1, 9),
(10, '80.00', 2, 10),
(11, '35.00', 0, 11);

-- --------------------------------------------------------

--
-- Structure de la table `concert`
--

CREATE TABLE `concert` (
  `IdConcert` int(11) NOT NULL,
  `DateConcert` date DEFAULT NULL,
  `HeureConcert` time DEFAULT NULL,
  `IdScene` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Contenu de la table `concert`
--

INSERT INTO `concert` (`IdConcert`, `DateConcert`, `HeureConcert`, `IdScene`) VALUES
(0, '2021-06-11', '19:00:00', 0),
(1, '2021-06-11', '19:30:00', 1),
(2, '2021-06-11', '19:30:00', 2),
(3, '2021-06-12', '19:00:00', 0),
(4, '2021-06-12', '19:30:00', 1),
(5, '2021-06-12', '19:30:00', 2),
(6, '2021-06-13', '19:00:00', 0),
(7, '2021-06-13', '19:30:00', 1),
(8, '2021-06-13', '19:30:00', 2);

-- --------------------------------------------------------

--
-- Structure de la table `festivalier`
--

CREATE TABLE `festivalier` (
  `IdFestivalier` int(11) NOT NULL,
  `PremierJourPresence` date DEFAULT NULL,
  `DernierJourPresence` date NOT NULL,
  `NomF` varchar(100) DEFAULT NULL,
  `PrenomF` varchar(100) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Contenu de la table `festivalier`
--

INSERT INTO `festivalier` (`IdFestivalier`, `PremierJourPresence`, `DernierJourPresence`, `NomF`, `PrenomF`) VALUES
(0, '2021-06-11', '2021-06-13', 'Nova', 'Mamie'),
(1, '2021-06-13', '2021-06-13', 'Daniel', 'Jacques'),
(2, '2021-06-11', '2021-06-11', 'Beaujet', 'Béatrice'),
(3, '2021-06-12', '2021-06-12', 'Pakanowki', 'Sixteen'),
(4, '2021-06-11', '2021-06-13', 'Cyrielle', 'Nel'),
(5, '2021-06-12', '2021-06-12', 'Robin', 'Albane'),
(6, '2021-06-11', '2021-06-13', 'Volkihar', 'Serena'),
(7, '2021-06-13', '2021-06-13', 'Arper', 'April'),
(8, '2021-06-12', '2021-06-13', 'Lallement', 'Paul'),
(9, '2021-06-11', '2021-06-12', 'Luette', 'Estère'),
(10, '2021-06-11', '2021-06-13', 'Le-Français', 'François'),
(11, '2021-06-11', '2021-06-11', 'Lobedoreye', 'Michelle');

-- --------------------------------------------------------

--
-- Structure de la table `genre_musique`
--

CREATE TABLE `genre_musique` (
  `IDGenre` int(11) NOT NULL,
  `IntituléGenre` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Contenu de la table `genre_musique`
--

INSERT INTO `genre_musique` (`IDGenre`, `IntituléGenre`) VALUES
(0, 'Rock'),
(1, 'Pop'),
(2, 'Electro');

-- --------------------------------------------------------

--
-- Structure de la table `groupe`
--

CREATE TABLE `groupe` (
  `IdGroupe` int(11) NOT NULL,
  `IntituleGroupe` varchar(100) DEFAULT NULL,
  `IDGenre` int(11) NOT NULL,
  `IdConcert` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Contenu de la table `groupe`
--

INSERT INTO `groupe` (`IdGroupe`, `IntituleGroupe`, `IDGenre`, `IdConcert`) VALUES
(0, 'Ultra Gerbouille', 0, 0),
(1, 'Black Aïl Pisse', 2, 0),
(2, 'Zeldin Park', 0, 3),
(3, 'Daft Jazz', 2, 3),
(4, 'A/BDD', 0, 6),
(5, 'Briseurs Couleurs', 1, 6),
(6, 'D3D', 1, 1),
(7, 'GhettoBlastTete', 1, 1),
(8, 'Groupe d\'Affronterie', 1, 1),
(9, 'Celine Fion', 1, 2),
(10, 'mini flo et bully', 1, 2),
(11, 'Vlad', 1, 2),
(12, 'Partenaire Monotone', 1, 4),
(13, 'eMule et Photo', 1, 4),
(14, 'Lorenzouille', 1, 4),
(15, 'Bruno Juin', 1, 5),
(16, 'Au revoir c\'est naze', 1, 7),
(17, 'Kwator', 1, 7),
(18, 'Lance Rocket Letal', 1, 7),
(19, 'Nirvanal', 0, 7),
(20, 'The Mickael 12', 1, 5),
(21, 'Les 5 Marrons', 1, 8),
(22, 'Waka Pink', 0, 8),
(23, 'AuberjAsiat', 0, 8);

-- --------------------------------------------------------

--
-- Structure de la table `instrument`
--

CREATE TABLE `instrument` (
  `IdInstru` int(11) NOT NULL,
  `IntituleInstru` varchar(100) DEFAULT NULL,
  `IdArtiste` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Contenu de la table `instrument`
--

INSERT INTO `instrument` (`IdInstru`, `IntituleInstru`, `IdArtiste`) VALUES
(0, 'GuitareNP', 0),
(1, 'BatterieMC', 1),
(2, 'GuitareFLL', 2),
(3, 'BasseMB', 3),
(4, 'VoixWUR', 4),
(5, 'VoixPDA', 5),
(6, 'VoixPF', 6),
(7, 'GuitareMCN', 7),
(8, 'GuitareBN', 8),
(9, 'BatterieRG', 9),
(10, 'BasseDW', 10);

-- --------------------------------------------------------

--
-- Structure de la table `salle_de_spectacle`
--

CREATE TABLE `salle_de_spectacle` (
  `IdSalle` int(11) NOT NULL,
  `TailleSalle` int(11) DEFAULT NULL,
  `IntituleSalle` varchar(100) DEFAULT NULL,
  `IdBatimentF` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Structure de la table `scene`
--

CREATE TABLE `scene` (
  `IdScene` int(11) NOT NULL,
  `TailleScene` int(11) DEFAULT NULL,
  `IntituleScene` varchar(100) DEFAULT NULL,
  `IdTerrain` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Contenu de la table `scene`
--

INSERT INTO `scene` (`IdScene`, `TailleScene`, `IntituleScene`, `IdTerrain`) VALUES
(0, 10000, 'ScenePpale', 2),
(1, 5000, 'SceneN2', 0),
(2, 5000, 'SceneN3', 1);

-- --------------------------------------------------------

--
-- Structure de la table `terrain_plein_air`
--

CREATE TABLE `terrain_plein_air` (
  `IdTerrain` int(11) NOT NULL,
  `TailleTerrain` int(11) DEFAULT NULL,
  `IntituleTerrain` varchar(100) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Contenu de la table `terrain_plein_air`
--

INSERT INTO `terrain_plein_air` (`IdTerrain`, `TailleTerrain`, `IntituleTerrain`) VALUES
(0, 20000, 'RiveGôche'),
(1, 20000, 'RiveDrouate'),
(2, 20000, 'Sillon Intra Festival');

-- --------------------------------------------------------

--
-- Structure de la table `typebillet`
--

CREATE TABLE `typebillet` (
  `IDType` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

--
-- Contenu de la table `typebillet`
--

INSERT INTO `typebillet` (`IDType`) VALUES
(0),
(1),
(2);

--
-- Index pour les tables exportées
--

--
-- Index pour la table `artiste`
--
ALTER TABLE `artiste`
  ADD PRIMARY KEY (`IdArtiste`),
  ADD KEY `IdGroupe` (`IdGroupe`);

--
-- Index pour la table `assister_à`
--
ALTER TABLE `assister_à`
  ADD PRIMARY KEY (`IdConcert`,`IdFestivalier`),
  ADD KEY `IdFestivalier` (`IdFestivalier`);

--
-- Index pour la table `batiment_ferme`
--
ALTER TABLE `batiment_ferme`
  ADD PRIMARY KEY (`IdBatimentF`),
  ADD KEY `IdTerrain` (`IdTerrain`);

--
-- Index pour la table `billet_d_entree`
--
ALTER TABLE `billet_d_entree`
  ADD PRIMARY KEY (`IdBillet`),
  ADD KEY `IDType` (`IDType`),
  ADD KEY `IdFestivalier` (`IdFestivalier`);

--
-- Index pour la table `concert`
--
ALTER TABLE `concert`
  ADD PRIMARY KEY (`IdConcert`),
  ADD KEY `IdScene` (`IdScene`);

--
-- Index pour la table `festivalier`
--
ALTER TABLE `festivalier`
  ADD PRIMARY KEY (`IdFestivalier`);

--
-- Index pour la table `genre_musique`
--
ALTER TABLE `genre_musique`
  ADD PRIMARY KEY (`IDGenre`);

--
-- Index pour la table `groupe`
--
ALTER TABLE `groupe`
  ADD PRIMARY KEY (`IdGroupe`),
  ADD KEY `IDGenre` (`IDGenre`),
  ADD KEY `IdConcert` (`IdConcert`);

--
-- Index pour la table `instrument`
--
ALTER TABLE `instrument`
  ADD PRIMARY KEY (`IdInstru`),
  ADD KEY `IdArtiste` (`IdArtiste`);

--
-- Index pour la table `salle_de_spectacle`
--
ALTER TABLE `salle_de_spectacle`
  ADD PRIMARY KEY (`IdSalle`),
  ADD KEY `IdBatimentF` (`IdBatimentF`);

--
-- Index pour la table `scene`
--
ALTER TABLE `scene`
  ADD PRIMARY KEY (`IdScene`),
  ADD KEY `IdTerrain` (`IdTerrain`);

--
-- Index pour la table `terrain_plein_air`
--
ALTER TABLE `terrain_plein_air`
  ADD PRIMARY KEY (`IdTerrain`);

--
-- Index pour la table `typebillet`
--
ALTER TABLE `typebillet`
  ADD PRIMARY KEY (`IDType`);

--
-- Contraintes pour les tables exportées
--

--
-- Contraintes pour la table `artiste`
--
ALTER TABLE `artiste`
  ADD CONSTRAINT `artiste_ibfk_1` FOREIGN KEY (`IdGroupe`) REFERENCES `groupe` (`IdGroupe`);

--
-- Contraintes pour la table `assister_à`
--
ALTER TABLE `assister_à`
  ADD CONSTRAINT `assister_à_ibfk_1` FOREIGN KEY (`IdConcert`) REFERENCES `concert` (`IdConcert`),
  ADD CONSTRAINT `assister_à_ibfk_2` FOREIGN KEY (`IdFestivalier`) REFERENCES `festivalier` (`IdFestivalier`);

--
-- Contraintes pour la table `batiment_ferme`
--
ALTER TABLE `batiment_ferme`
  ADD CONSTRAINT `batiment_ferme_ibfk_1` FOREIGN KEY (`IdTerrain`) REFERENCES `terrain_plein_air` (`IdTerrain`);

--
-- Contraintes pour la table `billet_d_entree`
--
ALTER TABLE `billet_d_entree`
  ADD CONSTRAINT `billet_d_entree_ibfk_1` FOREIGN KEY (`IDType`) REFERENCES `typebillet` (`IDType`),
  ADD CONSTRAINT `billet_d_entree_ibfk_2` FOREIGN KEY (`IdFestivalier`) REFERENCES `festivalier` (`IdFestivalier`);

--
-- Contraintes pour la table `concert`
--
ALTER TABLE `concert`
  ADD CONSTRAINT `concert_ibfk_1` FOREIGN KEY (`IdScene`) REFERENCES `scene` (`IdScene`);

--
-- Contraintes pour la table `groupe`
--
ALTER TABLE `groupe`
  ADD CONSTRAINT `groupe_ibfk_1` FOREIGN KEY (`IDGenre`) REFERENCES `genre_musique` (`IDGenre`),
  ADD CONSTRAINT `groupe_ibfk_2` FOREIGN KEY (`IdConcert`) REFERENCES `concert` (`IdConcert`);

--
-- Contraintes pour la table `instrument`
--
ALTER TABLE `instrument`
  ADD CONSTRAINT `instrument_ibfk_1` FOREIGN KEY (`IdArtiste`) REFERENCES `artiste` (`IdArtiste`);

--
-- Contraintes pour la table `salle_de_spectacle`
--
ALTER TABLE `salle_de_spectacle`
  ADD CONSTRAINT `salle_de_spectacle_ibfk_1` FOREIGN KEY (`IdBatimentF`) REFERENCES `batiment_ferme` (`IdBatimentF`);

--
-- Contraintes pour la table `scene`
--
ALTER TABLE `scene`
  ADD CONSTRAINT `scene_ibfk_1` FOREIGN KEY (`IdTerrain`) REFERENCES `terrain_plein_air` (`IdTerrain`);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
