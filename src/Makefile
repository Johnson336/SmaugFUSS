#!/usr/bin/make -f

########################################
#
#      Kallaikia v1.9.1 (Ith)
#
#      Basado en SMAUG 1.9 (FUSS)
#
########################################

NOMBRE = kallaikia
VERSION = 1.9.1
DESCRIPCION = O Reino das Tebras

########################################
# Opciones del servidor
########################################

#IMC2 - Comentar para deshabilitar el soporte IMC2 (Mud Network Chat)
IMC = -DIMC -DIMCSMAUG

# Comentar para incluir planos
PLANOS = -DPLANES


########################################
# Arquitectura del sistema
########################################

HOSTNAME = `hostname`
ARCH = `uname -m`

########################################
# Opciones para G++
########################################

CC      = g++
#PROF    = -p

#Descomentar si se obtienen referencias indefinidas para dlsym, dlopen, and dlclose.
#Comentar si se obtienen errores de ldl no encontrado.
NEED_DL = -ldl

#Algunos sistemas necesitan esto para el enlazado dinamico.
EXPORT_SYMBOLS = -export-dynamic

# Descomentar para modo desarrollo/debug  
# Comentar para modo distribucion
# CXX_FLAGS = -Wall -Wshadow -Wformat-security -Wpointer-arith -Wcast-align -Wredundant-decls -Wconversion -Wwrite-strings -Wunused-result

# Descomentar para modo distribucion
# Comentar para modo desarrollo/debug
CXX_FLAGS = -Wno-all -fpermissive -Wno-conversion -Wno-write-strings -Wno-shadow -Wno-format-security -Wno-pointer-arith -Wno-cast-align -Wno-redundant-decls -Wno-unused-result

########################################
# GCC FLAGS Completos
########################################

# DNS_FLAGS - Para el proceso resolver_dns, no es neceario enlazar todas las librerias.
DNS_FLAGS = -g2 -O -pipe $(PROF)

C_FLAGS = -O -g2 -pipe $(CXX_FLAGS) $(PROF) $(EXPORT_SYMBOLS) -DSMAUG

ifeq ($(ARCH), x86_64)
C_FLAGS := $(C_FLAGS) -march=$(ARCH) -mtune=$(ARCH)
else
C_FLAGS := $(C_FLAGS)
endif

L_FLAGS = $(PROF) -lz $(NEED_DL)

########################################
# Ficheros C para compilar
########################################

C_FILES = actualizar.c \
xadrez.c \
banear.c \
calendario.c \
clans.c \
clima.c \
cor.c \
comentarios.c \
comunicacions.c \
consellos.c \
constantes.c \
construir.c \
convertir_mapas.c \
crear_obxetos.c \
db.c \
deidades.c \
dns.c \
especial.c \
gardar.c \
manexador.c \
cifrarcadeas.c \
inicio.c \
interprete.c \
xogador.c \
xogador_combate.c \
xogador_comunicacions.c \
xogador_feitizos.c \
xogador_informacion.c \
xogador_inmortais_seguridade.c \
xogador_maxia.c \
xogador_movemento.c \
xogador_obxetos.c \
xogador_polimorfismo.c \
xogador_rastrexar.c \
xogador_varios.c \
xogador_wiz.c \
liquidos.c \
mapeador.c \
mccp.c \
mpxset.c \
novas.c \
kallaikia.c \
kallaikia_comunicacions.c \
renumerar.c \
resetear.c \
sha256.c \
taboas_datos.c \
taboeiros_de_anuncios.c \
tendas.c \
variables.c

# Ficheros adicionales para soporte IMC
ifdef IMC
   C_FILES := imc.c $(C_FILES)
   C_FLAGS := $(C_FLAGS) $(IMC)
endif

# Ficheros adicionales para Planos
ifdef PLANOS
   C_FILES := planos.c $(C_FILES)
   C_FLAGS := $(C_FLAGS) $(PLANOS)
endif

# Obxetos del compilador xeneranse en "obxetos_compilador"
O_FILES := $(patsubst %.c,obxetos_compilador/%.o,$(C_FILES))

H_FILES = $(wildcard *.h) 

########################################
# Construir el codigo
########################################

all: clean
	@mkdir obxetos_compilador
	@echo && echo " [ "$(MAKE)" ] Construccion -> \""$(NOMBRE)" "$(VERSION)" ("$(ARCH)")\" en $(HOSTNAME)." && echo
	@echo " [ "$(MAKE)" ] C_FLAGS -> \""$(C_FLAGS)"\"" && echo  
	@$(MAKE) -s $(NOMBRE)
	@echo && echo " [ "$(MAKE)" ] Construccion -> \""$(NOMBRE)"\" buscador DNS." && echo
	@$(MAKE) -s resolver_dns
	@echo " [ "$(MAKE)" ] Finalizado! -> \""$(NOMBRE)" "$(VERSION)" ("$(ARCH)")\"." && echo

# Incluir las dependencias para los obxetos existentes
-include dependencies.d

$(NOMBRE): $(O_FILES)
	rm -f ../$(NOMBRE)
	$(CC) -export-dynamic -o ../$(NOMBRE) $(O_FILES) $(L_FLAGS)
	@echo && echo " [ "$(MAKE)" ] Xerar o ficheiro de dependencia \"dependencies.d\".";
	@$(CC) -MM $(C_FLAGS) $(C_FILES) > dependencies.d
	@perl -pi -e 's.^([a-z]).o/$$1.g' dependencies.d
	echo " [ "$(MAKE)" ] Finalizada a construccion de: \""$(NOMBRE)"\"."
	chmod g+w ../$(NOMBRE)
	chmod a+x ../$(NOMBRE)
	chmod g+w $(O_FILES)

resolver_dns: obxetos_compilador/resolver_dns.o
	rm -f ../resolver_dns
	$(CC) $(DNS_FLAGS) -o ../resolver_dns obxetos_compilador/resolver_dns.o
	@echo " [ "$(MAKE)" ] Finalizada a construccion de buscador DNS: \"resolver_dns\"." && echo
	chmod g+w ../resolver_dns
	chmod a+x ../resolver_dns

obxetos_compilador/%.o: %.c
	echo " [ "$(CC)" ] Construir -> $@ ... "
	$(CC) -c $(C_FLAGS) $< -o $@

.c.o: $(NOMBRE).h
	$(CC) -c $(C_FLAGS) $<

clean:
	@rm -rfv obxetos_compilador dependencies.d *~ ../*/*~ ../*~

cleanall:
	@rm -rfv ../$(NOMBRE) obxetos_compilador dependencies.d ../resolver_dns *~ ../*/*~ ../*~

dist:
	@echo && echo " [ "$(MAKE)" ] Limpar obxetos do codigo e ficheros de log ..." && echo
	@$(MAKE) -s clean && cd .. && touch logs/$(NOMBRE).log && rm -v logs/*
	@echo && echo " [ "$(MAKE)" ] Creando o ficheiro de distribucion: \"../../"$(NOMBRE)"-"$(VERSION)".tar.bz2\" ..."
	@cd .. && tar cfj ../$(NOMBRE)-$(VERSION).tar.bz2 *
	@echo " [ "$(MAKE)" ] Finalizado." && echo

git:
	@$(MAKE) -s cleanall; \
	cd ..; \
	git add -A; \
	git commit -m "Publicado desde $(HOSTNAME)"; \
	git push origin master

