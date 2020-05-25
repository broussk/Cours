SET foreign_key_checks = 0;
DROP TABLE IF EXISTS Bateau ;
CREATE TABLE Bateau (Immatriculation_Bateau VARCHAR(40) NOT NULL,
Nom_Bateau TEXT,
AnneeConstru_Bateau INT,
Marque_Bateau TEXT,
typeB TEXT,
Dimension_Bateau TEXT,
nbPlaces_Bateau INT,
poids_Bateau INT,
capaCarbu_Bateau INT,
capaEau_Bateau INT,
motorisation_Bateau TEXT,
PRIMARY KEY (Immatriculation_Bateau)) ENGINE=InnoDB;

DROP TABLE IF EXISTS Revision_Periodique ;
CREATE TABLE Revision_Periodique (IdRevi_Revision_Periodique INT unsigned NOT NULL,
date_Revision_Periodique INT,
kilometrage_Revision_Periodique INT,
PRIMARY KEY (IdRevi_Revision_Periodique)) ENGINE=InnoDB;

DROP TABLE IF EXISTS Securite_Obligatoire ;
CREATE TABLE Securite_Obligatoire (IdSecu_Securite_Obligatoire INT unsigned AUTO_INCREMENT NOT NULL,
dureeVieMax_Securite_Obligatoire INT,
revisionPeriodique_Securite_Obligatoire INT,
nomObjet_Securite_Obligatoire TEXT,
typeBateau_Securite_Obligatoire TEXT,
Immatriculation_Bateau VARCHAR(40),
PRIMARY KEY (IdSecu_Securite_Obligatoire)) ENGINE=InnoDB;

DROP TABLE IF EXISTS Entretien_Courant ;
CREATE TABLE Entretien_Courant (IdEntre_Entretien_Courant INT unsigned AUTO_INCREMENT NOT NULL,
RepPieceCassee TEXT,
changementPieceUsure TEXT,
PRIMARY KEY (IdEntre_Entretien_Courant)) ENGINE=InnoDB;

DROP TABLE IF EXISTS Moteur ;
CREATE TABLE Moteur (IdMoteur_Moteur INT unsigned AUTO_INCREMENT NOT NULL,
nomMoteur_Moteur TEXT,
typeMoteur_Moteur TEXT,
pieceMoteur_Moteur TEXT,
marqueMoteur_Moteur TEXT,
capaMoteur_Moteur INT,
PRIMARY KEY (IdMoteur_Moteur)) ENGINE=InnoDB;

DROP TABLE IF EXISTS Pieces ;
CREATE TABLE Pieces (idPiece_Pieces INT unsigned AUTO_INCREMENT NOT NULL,
marquePiece_Pieces TEXT,
nomPiece_Pieces TEXT,
PRIMARY KEY (idPiece_Pieces)) ENGINE=InnoDB;

DROP TABLE IF EXISTS Fournisseur ;
CREATE TABLE Fournisseur (idFournisseur_Fournisseur INT unsigned AUTO_INCREMENT NOT NULL,
nomFournisseur_Fournisseur TEXT,
adresseFournisseur_Fournisseur TEXT,
telFournisseur_Fournisseur TEXT,
PRIMARY KEY (idFournisseur_Fournisseur)) ENGINE=InnoDB;

DROP TABLE IF EXISTS Reservoir ;
CREATE TABLE Reservoir (idReservoir_Reservoir INT unsigned AUTO_INCREMENT NOT NULL,
marqueReservoir_Reservoir TEXT,
typeReservoir_Reservoir TEXT,
capaciteReservoir_Reservoir INT,
PRIMARY KEY (idReservoir_Reservoir)) ENGINE=InnoDB;

DROP TABLE IF EXISTS effectuee ;
CREATE TABLE effectuee (Immatriculation_Bateau VARCHAR(40) NOT NULL,
IdRevi_Revision_Periodique INT unsigned NOT NULL,
IdEntre_Entretien_Courant INT unsigned NOT NULL,
PRIMARY KEY (Immatriculation_Bateau,
 IdRevi_Revision_Periodique,
 IdEntre_Entretien_Courant)) ENGINE=InnoDB;

DROP TABLE IF EXISTS possede ;
CREATE TABLE possede (IdMoteur_Moteur INT unsigned AUTO_INCREMENT NOT NULL,
Immatriculation_Bateau VARCHAR(40) NOT NULL,
idReservoir_Reservoir INT unsigned NOT NULL,
PRIMARY KEY (IdMoteur_Moteur,
 Immatriculation_Bateau,
 idReservoir_Reservoir)) ENGINE=InnoDB;

DROP TABLE IF EXISTS compose_de ;
CREATE TABLE compose_de (IdMoteur_Moteur INT unsigned AUTO_INCREMENT NOT NULL,
idPiece_Pieces INT unsigned NOT NULL,
idReservoir_Reservoir INT unsigned NOT NULL,
PRIMARY KEY (IdMoteur_Moteur,
 idPiece_Pieces,
 idReservoir_Reservoir)) ENGINE=InnoDB;

DROP TABLE IF EXISTS fourni ;
CREATE TABLE fourni (idFournisseur_Fournisseur INT unsigned AUTO_INCREMENT NOT NULL,
idPiece_Pieces INT unsigned NOT NULL,
PRIMARY KEY (idFournisseur_Fournisseur,
 idPiece_Pieces)) ENGINE=InnoDB;

DROP TABLE IF EXISTS necessaire ;
CREATE TABLE necessaire (idPiece_Pieces INT unsigned AUTO_INCREMENT NOT NULL,
IdEntre_Entretien_Courant INT unsigned NOT NULL,
PRIMARY KEY (idPiece_Pieces,
 IdEntre_Entretien_Courant)) ENGINE=InnoDB;

ALTER TABLE Securite_Obligatoire ADD CONSTRAINT FK_Securite_Obligatoire_Immatriculation_Bateau FOREIGN KEY (Immatriculation_Bateau) REFERENCES Bateau (Immatriculation_Bateau);

ALTER TABLE effectuee ADD CONSTRAINT FK_effectuee_Immatriculation_Bateau FOREIGN KEY (Immatriculation_Bateau) REFERENCES Bateau (Immatriculation_Bateau);
ALTER TABLE effectuee ADD CONSTRAINT FK_effectuee_IdRevi_Revision_Periodique FOREIGN KEY (IdRevi_Revision_Periodique) REFERENCES Revision_Periodique (IdRevi_Revision_Periodique);
ALTER TABLE effectuee ADD CONSTRAINT FK_effectuee_IdEntre_Entretien_Courant FOREIGN KEY (IdEntre_Entretien_Courant) REFERENCES Entretien_Courant (IdEntre_Entretien_Courant);
ALTER TABLE possede ADD CONSTRAINT FK_possede_IdMoteur_Moteur FOREIGN KEY (IdMoteur_Moteur) REFERENCES Moteur (IdMoteur_Moteur);
ALTER TABLE possede ADD CONSTRAINT FK_possede_Immatriculation_Bateau FOREIGN KEY (Immatriculation_Bateau) REFERENCES Bateau (Immatriculation_Bateau);
ALTER TABLE possede ADD CONSTRAINT FK_possede_idReservoir_Reservoir FOREIGN KEY (idReservoir_Reservoir) REFERENCES Reservoir (idReservoir_Reservoir);
ALTER TABLE compose_de ADD CONSTRAINT FK_compose_de_IdMoteur_Moteur FOREIGN KEY (IdMoteur_Moteur) REFERENCES Moteur (IdMoteur_Moteur);
ALTER TABLE compose_de ADD CONSTRAINT FK_compose_de_idPiece_Pieces FOREIGN KEY (idPiece_Pieces) REFERENCES Pieces (idPiece_Pieces);
ALTER TABLE compose_de ADD CONSTRAINT FK_compose_de_idReservoir_Reservoir FOREIGN KEY (idReservoir_Reservoir) REFERENCES Reservoir (idReservoir_Reservoir);
ALTER TABLE fourni ADD CONSTRAINT FK_fourni_idFournisseur_Fournisseur FOREIGN KEY (idFournisseur_Fournisseur) REFERENCES Fournisseur (idFournisseur_Fournisseur);
ALTER TABLE fourni ADD CONSTRAINT FK_fourni_idPiece_Pieces FOREIGN KEY (idPiece_Pieces) REFERENCES Pieces (idPiece_Pieces);
ALTER TABLE necessaire ADD CONSTRAINT FK_necessaire_idPiece_Pieces FOREIGN KEY (idPiece_Pieces) REFERENCES Pieces (idPiece_Pieces);
ALTER TABLE necessaire ADD CONSTRAINT FK_necessaire_IdEntre_Entretien_Courant FOREIGN KEY (IdEntre_Entretien_Courant) REFERENCES Entretien_Courant (IdEntre_Entretien_Courant);
