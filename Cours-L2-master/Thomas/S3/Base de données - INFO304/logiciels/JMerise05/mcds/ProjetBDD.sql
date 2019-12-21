#------------------------------------------------------------
#        Script MySQL.
#------------------------------------------------------------


#------------------------------------------------------------
# Table: Client
#------------------------------------------------------------

CREATE TABLE Client(
        IdCl  Int NOT NULL ,
        NomCl Varchar (30) NOT NULL ,
        PrnCl Varchar (30) NOT NULL ,
        TelCl Varchar (10) NOT NULL
	,CONSTRAINT Client_PK PRIMARY KEY (IdCl)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: Employe
#------------------------------------------------------------

CREATE TABLE Employe(
        IdE      Int NOT NULL ,
        NomE     Varchar (30) NOT NULL ,
        PrenomE  Varchar (30) NOT NULL ,
        TelE     Int NOT NULL ,
        SalaireE Double NOT NULL ,
        TauxHE   Double NOT NULL ,
        DipE     Varchar (30) NOT NULL
	,CONSTRAINT Employe_PK PRIMARY KEY (IdE)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: Emplacement
#------------------------------------------------------------

CREATE TABLE Emplacement(
        IdEmp     Int NOT NULL ,
        TailleEmp Int NOT NULL ,
        PrixEmp   Int NOT NULL ,
        AdrEmp    Varchar (60) NOT NULL
	,CONSTRAINT Emplacement_PK PRIMARY KEY (IdEmp)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: Emplacement_Libre
#------------------------------------------------------------

CREATE TABLE Emplacement_Libre(
        IdEmp_Libre Int NOT NULL ,
        Evacuation  Bool NOT NULL
	,CONSTRAINT Emplacement_Libre_PK PRIMARY KEY (IdEmp_Libre)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: Emplacement_MobilHome
#------------------------------------------------------------

CREATE TABLE Emplacement_MobilHome(
        IdEmp_MobilHome Int NOT NULL ,
        Type_MobilHome  Varchar (30) NOT NULL
	,CONSTRAINT Emplacement_MobilHome_PK PRIMARY KEY (IdEmp_MobilHome)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: Animateur
#------------------------------------------------------------

CREATE TABLE Animateur(
        IdInt Int NOT NULL
	,CONSTRAINT Animateur_PK PRIMARY KEY (IdInt)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: Secretaire
#------------------------------------------------------------

CREATE TABLE Secretaire(
        IdSecretaire Int NOT NULL
	,CONSTRAINT Secretaire_PK PRIMARY KEY (IdSecretaire)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: Activité
#------------------------------------------------------------

CREATE TABLE Activite(
        IdAct    Int NOT NULL ,
        NomAct   Varchar (30) NOT NULL ,
        DureeAct Int NOT NULL ,
        DateAct  Int NOT NULL ,
        PrixAct  Int NOT NULL
	,CONSTRAINT Activite_PK PRIMARY KEY (IdAct)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: Piscine
#------------------------------------------------------------

CREATE TABLE Piscine(
        IdPiscine Int NOT NULL
	,CONSTRAINT Piscine_PK PRIMARY KEY (IdPiscine)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: Planning
#------------------------------------------------------------

CREATE TABLE Planning(
        IdPlanning       Int NOT NULL ,
        HoraireOuverture Int NOT NULL ,
        HoraireFermeture Int NOT NULL
	,CONSTRAINT Planning_PK PRIMARY KEY (IdPlanning)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: ClubEnfant
#------------------------------------------------------------

CREATE TABLE ClubEnfant(
        IdClubEnfant Int NOT NULL ,
        AgeMin       Int NOT NULL ,
        AgeMax       Int NOT NULL
	,CONSTRAINT ClubEnfant_PK PRIMARY KEY (IdClubEnfant)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: Terrain
#------------------------------------------------------------

CREATE TABLE Terrain(
        IdTerrain Int NOT NULL
	,CONSTRAINT Terrain_PK PRIMARY KEY (IdTerrain)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: Diplome
#------------------------------------------------------------

CREATE TABLE Diplome(
        IdDip Int NOT NULL ,
        DipE  Int NOT NULL
	,CONSTRAINT Diplome_PK PRIMARY KEY (IdDip)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: Barman
#------------------------------------------------------------

CREATE TABLE Barman(
        IdBarman Int NOT NULL
	,CONSTRAINT Barman_PK PRIMARY KEY (IdBarman)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: Serveur
#------------------------------------------------------------

CREATE TABLE Serveur(
        IdServeur Int NOT NULL
	,CONSTRAINT Serveur_PK PRIMARY KEY (IdServeur)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: Participer
#------------------------------------------------------------

CREATE TABLE Participer(
        IdAct Int NOT NULL ,
        IdCl  Int NOT NULL
	,CONSTRAINT Participer_PK PRIMARY KEY (IdAct,IdCl)

	,CONSTRAINT Participer_Activite_FK FOREIGN KEY (IdAct) REFERENCES Activite(IdAct)
	,CONSTRAINT Participer_Client0_FK FOREIGN KEY (IdCl) REFERENCES Client(IdCl)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: ETRE
#------------------------------------------------------------

CREATE TABLE ETRE(
        IdE          Int NOT NULL ,
        IdSecretaire Int NOT NULL ,
        IdInt        Int NOT NULL ,
        IdBarman     Int NOT NULL ,
        IdServeur    Int NOT NULL
	,CONSTRAINT ETRE_PK PRIMARY KEY (IdE,IdSecretaire,IdInt,IdBarman,IdServeur)

	,CONSTRAINT ETRE_Employe_FK FOREIGN KEY (IdE) REFERENCES Employe(IdE)
	,CONSTRAINT ETRE_Secretaire0_FK FOREIGN KEY (IdSecretaire) REFERENCES Secretaire(IdSecretaire)
	,CONSTRAINT ETRE_Animateur1_FK FOREIGN KEY (IdInt) REFERENCES Animateur(IdInt)
	,CONSTRAINT ETRE_Barman2_FK FOREIGN KEY (IdBarman) REFERENCES Barman(IdBarman)
	,CONSTRAINT ETRE_Serveur3_FK FOREIGN KEY (IdServeur) REFERENCES Serveur(IdServeur)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: ETAT_EMPLACEMENT
#------------------------------------------------------------

CREATE TABLE ETAT_EMPLACEMENT(
        IdEmp           Int NOT NULL ,
        IdEmp_Libre     Int NOT NULL ,
        IdEmp_MobilHome Int NOT NULL
	,CONSTRAINT ETAT_EMPLACEMENT_PK PRIMARY KEY (IdEmp,IdEmp_Libre,IdEmp_MobilHome)

	,CONSTRAINT ETAT_EMPLACEMENT_Emplacement_FK FOREIGN KEY (IdEmp) REFERENCES Emplacement(IdEmp)
	,CONSTRAINT ETAT_EMPLACEMENT_Emplacement_Libre0_FK FOREIGN KEY (IdEmp_Libre) REFERENCES Emplacement_Libre(IdEmp_Libre)
	,CONSTRAINT ETAT_EMPLACEMENT_Emplacement_MobilHome1_FK FOREIGN KEY (IdEmp_MobilHome) REFERENCES Emplacement_MobilHome(IdEmp_MobilHome)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: ANIMER
#------------------------------------------------------------

CREATE TABLE ANIMER(
        IdAct Int NOT NULL ,
        IdInt Int NOT NULL
	,CONSTRAINT ANIMER_PK PRIMARY KEY (IdAct,IdInt)

	,CONSTRAINT ANIMER_Activite_FK FOREIGN KEY (IdAct) REFERENCES Activite(IdAct)
	,CONSTRAINT ANIMER_Animateur0_FK FOREIGN KEY (IdInt) REFERENCES Animateur(IdInt)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: SERVIR
#------------------------------------------------------------

CREATE TABLE SERVIR(
        IdCl      Int NOT NULL ,
        IdServeur Int NOT NULL ,
        IdBarman  Int NOT NULL
	,CONSTRAINT SERVIR_PK PRIMARY KEY (IdCl,IdServeur,IdBarman)

	,CONSTRAINT SERVIR_Client_FK FOREIGN KEY (IdCl) REFERENCES Client(IdCl)
	,CONSTRAINT SERVIR_Serveur0_FK FOREIGN KEY (IdServeur) REFERENCES Serveur(IdServeur)
	,CONSTRAINT SERVIR_Barman1_FK FOREIGN KEY (IdBarman) REFERENCES Barman(IdBarman)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: GERER
#------------------------------------------------------------

CREATE TABLE GERER(
        IdPlanning   Int NOT NULL ,
        IdSecretaire Int NOT NULL
	,CONSTRAINT GERER_PK PRIMARY KEY (IdPlanning,IdSecretaire)

	,CONSTRAINT GERER_Planning_FK FOREIGN KEY (IdPlanning) REFERENCES Planning(IdPlanning)
	,CONSTRAINT GERER_Secretaire0_FK FOREIGN KEY (IdSecretaire) REFERENCES Secretaire(IdSecretaire)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: CORRESPOND
#------------------------------------------------------------

CREATE TABLE CORRESPOND(
        IdAct      Int NOT NULL ,
        IdPlanning Int NOT NULL
	,CONSTRAINT CORRESPOND_PK PRIMARY KEY (IdAct,IdPlanning)

	,CONSTRAINT CORRESPOND_Activite_FK FOREIGN KEY (IdAct) REFERENCES Activite(IdAct)
	,CONSTRAINT CORRESPOND_Planning0_FK FOREIGN KEY (IdPlanning) REFERENCES Planning(IdPlanning)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: CONSISTER
#------------------------------------------------------------

CREATE TABLE CONSISTER(
        IdAct        Int NOT NULL ,
        IdPiscine    Int NOT NULL ,
        IdClubEnfant Int NOT NULL ,
        IdTerrain    Int NOT NULL
	,CONSTRAINT CONSISTER_PK PRIMARY KEY (IdAct,IdPiscine,IdClubEnfant,IdTerrain)

	,CONSTRAINT CONSISTER_Activite_FK FOREIGN KEY (IdAct) REFERENCES Activite(IdAct)
	,CONSTRAINT CONSISTER_Piscine0_FK FOREIGN KEY (IdPiscine) REFERENCES Piscine(IdPiscine)
	,CONSTRAINT CONSISTER_ClubEnfant1_FK FOREIGN KEY (IdClubEnfant) REFERENCES ClubEnfant(IdClubEnfant)
	,CONSTRAINT CONSISTER_Terrain2_FK FOREIGN KEY (IdTerrain) REFERENCES Terrain(IdTerrain)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: LOUER
#------------------------------------------------------------

CREATE TABLE LOUER(
        IdEmp Int NOT NULL ,
        IdCl  Int NOT NULL
	,CONSTRAINT LOUER_PK PRIMARY KEY (IdEmp,IdCl)

	,CONSTRAINT LOUER_Emplacement_FK FOREIGN KEY (IdEmp) REFERENCES Emplacement(IdEmp)
	,CONSTRAINT LOUER_Client0_FK FOREIGN KEY (IdCl) REFERENCES Client(IdCl)
)ENGINE=InnoDB;


#------------------------------------------------------------
# Table: POSSEDER
#------------------------------------------------------------

CREATE TABLE POSSEDER(
        IdDip Int NOT NULL ,
        IdE   Int NOT NULL
	,CONSTRAINT POSSEDER_PK PRIMARY KEY (IdDip,IdE)

	,CONSTRAINT POSSEDER_Diplome_FK FOREIGN KEY (IdDip) REFERENCES Diplome(IdDip)
	,CONSTRAINT POSSEDER_Employe0_FK FOREIGN KEY (IdE) REFERENCES Employe(IdE)
)ENGINE=InnoDB;

