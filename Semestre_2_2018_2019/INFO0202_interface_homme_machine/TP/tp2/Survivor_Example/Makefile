SOURCEPATH = src
CLASSPATH  = misc
CLASSES    = classes
DOCS       = docs
PACKAGE    = theSurvivor

JAVAC      = javac
JAVA       = java
JAVADOC    = javadoc

OBJECTS    = Zone.class Manager.class ExitAction.class TheSurvivorWindows.class TheSurvivorConfiguration.class RunTheSurvivor.class

TARGET     = RunTheSurvivor

ALL: RunTheSurvivor

help:
	@echo "(C) JC.Boisson"
	@echo "Sous-commandes :"
	@echo "compil           : compile tous les fichiers java du projet."
	@echo "RunTheSurvivor   : exécute le jeu après l'avoir compilé, commande par défaut."
	@echo "docs             : génère la javadoc."
	@echo "clean            : supprime *tous* les fichiers reproductibles."

%.class: $(SOURCEPATH)/$(PACKAGE)/%.java
	-@mkdir -p $(CLASSES) 2> /dev/null
	-@$(JAVAC) -d $(CLASSES) -classpath $(CLASSPATH):$(CLASSES) -sourcepath $(SOURCEPATH) $<
	-@echo "==> $@"

compil: clean $(OBJECTS)
	@echo ""
	@echo "Compilation ended"

RunTheSurvivor: clean $(OBJECTS)
	@$(JAVA) -classpath $(CLASSES):$(CLASSPATH) $(PACKAGE).$@

docs:
	-@mkdir $(DOCS)
	@$(JAVADOC) -d $(DOCS) -version -author -private $(SOURCEPATH)/$(PACKAGE)/*.java -classpath $(CLASSPATH)


clean:
	-@rm -rf $(CLASSES) $(DOCS)
	-@find . \( -name "*~" -o -name "*.old" -o -name "#*" -o -name "*.bak" \) -print -exec rm -rf \{\} \;

.PHONY: ALL $(TARGET) run clean docs help

