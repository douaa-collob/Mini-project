#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
char nom[50];
int numeroCompte;
char motDePasse[20];
float solde;
} Compte;

Compte comptes[MAX_ACCOUNTS];
int nombreComptes = 0;

void creerCompte() {
if (nombreComptes >= MAX_ACCOUNTS) {
printf("Nombre maximum de comptes atteint.\n");
return;
}

Compte nouveau;

printf("Entrez votre nom : ");
scanf(" %[^\n]", nouveau.nom);

printf("Entrez un numéro de compte : ");
scanf("%d", &nouveau.numeroCompte);

printf("Choisissez un mot de passe : ");
scanf("%s", nouveau.motDePasse);

nouveau.solde = 0.0;

comptes[nombreComptes++] = nouveau;

printf("Compte créé avec succès !\n");
}

int seConnecter() {
int numero;
char motDePasse[20];

printf("Entrez votre numéro de compte : ");
scanf("%d", &numero);

printf("Entrez votre mot de passe : ");
scanf("%s", motDePasse);

for (int i = 0; i < nombreComptes; i++) {
if (comptes[i].numeroCompte == numero && strcmp(comptes[i].motDePasse, motDePasse) == 0) {
printf("Connexion réussie !\n");
return i;
}
}

printf("Échec de la connexion.\n");
return -1;
}

void deposerArgent(int index) {
float montant;
printf("Entrez le montant à déposer : ");
scanf("%f", &montant);

if (montant > 0) {
comptes[index].solde += montant;
printf("Dépôt réussi. Nouveau solde : %.2f\n", comptes[index].solde);
} else {
printf("Montant invalide.\n");
}
}

void transfererArgent(int index) {
int numeroDest;
float montant;
printf("Entrez le numéro de compte du destinataire : ");
scanf("%d", &numeroDest);

printf("Entrez le montant à transférer : ");
scanf("%f", &montant);

if (montant <= 0 || montant > comptes[index].solde) {
printf("Montant invalide ou solde insuffisant.\n");
return;
}

for (int i = 0; i < nombreComptes; i++) {
if (comptes[i].numeroCompte == numeroDest) {
comptes[index].solde -= montant;
comptes[i].solde += montant;
printf("Transfert réussi.\n");
return;
}
}

printf("Compte destinataire introuvable.\n");
}

void afficherSolde(int index) {
printf("Votre solde est : %.2f\n", comptes[index].solde);
}

void supprimerCompte(int index) {
if (comptes[index].solde != 0) {
printf("Impossible de supprimer le compte : solde non nul.\n");
return;
}

for (int i = index; i < nombreComptes - 1; i++) {
comptes[i] = comptes[i + 1];
}

nombreComptes--;
printf("Compte supprimé avec succès.\n");
}

void menuPrincipal() {
int choix, index;

do {
printf("\n--- MENU PRINCIPAL ---\n");
printf("1. Créer un compte\n");
printf("2. Se connecter\n");
printf("3. Quitter\n");
printf("Choix : ");
scanf("%d", &choix);

switch (choix) {
case 1:
creerCompte();
break;
case 2:
index = seConnecter();
if (index != -1) {
int action;
do {
printf("\n1. Déposer de l'argent\n");
printf("2. Transférer de l'argent\n");
printf("3. Consulter le solde\n");
printf("4. Supprimer le compte\n");
printf("5. Se déconnecter\n");
printf("Choix : ");
scanf("%d", &action);

switch (action) {
case 1: deposerArgent(index); break;
case 2: transfererArgent(index); break;
case 3: afficherSolde(index); break;
case 4: supprimerCompte(index); action = 5; break;
}
} while (action != 5);
}
break;
}

} while (choix != 3);

printf("Merci d'avoir utilisé notre système bancaire.\n");
}

int main() {
menuPrincipal();
return 0;
}#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
char nom[50];
int numeroCompte;
char motDePasse[20];
float solde;
} Compte;

Compte comptes[MAX_ACCOUNTS];
int nombreComptes = 0;

void creerCompte() {
if (nombreComptes >= MAX_ACCOUNTS) {
printf("Nombre maximum de comptes atteint.\n");
return;
}

Compte nouveau;

printf("Entrez votre nom : ");
scanf(" %[^\n]", nouveau.nom);

printf("Entrez un numéro de compte : ");
scanf("%d", &nouveau.numeroCompte);

printf("Choisissez un mot de passe : ");
scanf("%s", nouveau.motDePasse);

nouveau.solde = 0.0;

comptes[nombreComptes++] = nouveau;

printf("Compte créé avec succès !\n");
}

int seConnecter() {
int numero;
char motDePasse[20];

printf("Entrez votre numéro de compte : ");
scanf("%d", &numero);

printf("Entrez votre mot de passe : ");
scanf("%s", motDePasse);

for (int i = 0; i < nombreComptes; i++) {
if (comptes[i].numeroCompte == numero && strcmp(comptes[i].motDePasse, motDePasse) == 0) {
printf("Connexion réussie !\n");
return i;
}
}

printf("Échec de la connexion.\n");
return -1;
}

void deposerArgent(int index) {
float montant;
printf("Entrez le montant à déposer : ");
scanf("%f", &montant);

if (montant > 0) {
comptes[index].solde += montant;
printf("Dépôt réussi. Nouveau solde : %.2f\n", comptes[index].solde);
} else {
printf("Montant invalide.\n");
}
}

void transfererArgent(int index) {
int numeroDest;
float montant;
printf("Entrez le numéro de compte du destinataire : ");
scanf("%d", &numeroDest);

printf("Entrez le montant à transférer : ");
scanf("%f", &montant);

if (montant <= 0 || montant > comptes[index].solde) {
printf("Montant invalide ou solde insuffisant.\n");
return;
}

for (int i = 0; i < nombreComptes; i++) {
if (comptes[i].numeroCompte == numeroDest) {
comptes[index].solde -= montant;
comptes[i].solde += montant;
printf("Transfert réussi.\n");
return;
}
}

printf("Compte destinataire introuvable.\n");
}

void afficherSolde(int index) {
printf("Votre solde est : %.2f\n", comptes[index].solde);
}

void supprimerCompte(int index) {
if (comptes[index].solde != 0) {
printf("Impossible de supprimer le compte : solde non nul.\n");
return;
}

for (int i = index; i < nombreComptes - 1; i++) {
comptes[i] = comptes[i + 1];
}

nombreComptes--;
printf("Compte supprimé avec succès.\n");
}

void menuPrincipal() {
int choix, index;

do {
printf("\n--- MENU PRINCIPAL ---\n");
printf("1. Créer un compte\n");
printf("2. Se connecter\n");
printf("3. Quitter\n");
printf("Choix : ");
scanf("%d", &choix);

switch (choix) {
case 1:
creerCompte();
break;
case 2:
index = seConnecter();
if (index != -1) {
int action;
do {
printf("\n1. Déposer de l'argent\n");
printf("2. Transférer de l'argent\n");
printf("3. Consulter le solde\n");
printf("4. Supprimer le compte\n");
printf("5. Se déconnecter\n");
printf("Choix : ");
scanf("%d", &action);

switch (action) {
case 1: deposerArgent(index); break;
case 2: transfererArgent(index); break;
case 3: afficherSolde(index); break;
case 4: supprimerCompte(index); action = 5; break;
}
} while (action != 5);
}
break;
}

} while (choix != 3);

printf("Merci d'avoir utilisé notre système bancaire.\n");
}

int main() {
menuPrincipal();
return 0;
}#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
char nom[50];
int numeroCompte;
char motDePasse[20];
float solde;
} Compte;

Compte comptes[MAX_ACCOUNTS];
int nombreComptes = 0;

void creerCompte() {
if (nombreComptes >= MAX_ACCOUNTS) {
printf("Nombre maximum de comptes atteint.\n");
return;
}

Compte nouveau;

printf("Entrez votre nom : ");
scanf(" %[^\n]", nouveau.nom);

printf("Entrez un numéro de compte : ");
scanf("%d", &nouveau.numeroCompte);

printf("Choisissez un mot de passe : ");
scanf("%s", nouveau.motDePasse);

nouveau.solde = 0.0;

comptes[nombreComptes++] = nouveau;

printf("Compte créé avec succès !\n");
}

int seConnecter() {
int numero;
char motDePasse[20];

printf("Entrez votre numéro de compte : ");
scanf("%d", &numero);

printf("Entrez votre mot de passe : ");
scanf("%s", motDePasse);

for (int i = 0; i < nombreComptes; i++) {
if (comptes[i].numeroCompte == numero && strcmp(comptes[i].motDePasse, motDePasse) == 0) {
printf("Connexion réussie !\n");
return i;
}
}

printf("Échec de la connexion.\n");
return -1;
}

void deposerArgent(int index) {
float montant;
printf("Entrez le montant à déposer : ");
scanf("%f", &montant);

if (montant > 0) {
comptes[index].solde += montant;
printf("Dépôt réussi. Nouveau solde : %.2f\n", comptes[index].solde);
} else {
printf("Montant invalide.\n");
}
}

void transfererArgent(int index) {
int numeroDest;
float montant;
printf("Entrez le numéro de compte du destinataire : ");
scanf("%d", &numeroDest);

printf("Entrez le montant à transférer : ");
scanf("%f", &montant);

if (montant <= 0 || montant > comptes[index].solde) {
printf("Montant invalide ou solde insuffisant.\n");
return;
}

for (int i = 0; i < nombreComptes; i++) {
if (comptes[i].numeroCompte == numeroDest) {
comptes[index].solde -= montant;
comptes[i].solde += montant;
printf("Transfert réussi.\n");
return;
}
}

printf("Compte destinataire introuvable.\n");
}

void afficherSolde(int index) {
printf("Votre solde est : %.2f\n", comptes[index].solde);
}

void supprimerCompte(int index) {
if (comptes[index].solde != 0) {
printf("Impossible de supprimer le compte : solde non nul.\n");
return;
}

for (int i = index; i < nombreComptes - 1; i++) {
comptes[i] = comptes[i + 1];
}

nombreComptes--;
printf("Compte supprimé avec succès.\n");
}

void menuPrincipal() {
int choix, index;

do {
printf("\n--- MENU PRINCIPAL ---\n");
printf("1. Créer un compte\n");
printf("2. Se connecter\n");
printf("3. Quitter\n");
printf("Choix : ");
scanf("%d", &choix);

switch (choix) {
case 1:
creerCompte();
break;
case 2:
index = seConnecter();
if (index != -1) {
int action;
do {
printf("\n1. Déposer de l'argent\n");
printf("2. Transférer de l'argent\n");
printf("3. Consulter le solde\n");
printf("4. Supprimer le compte\n");
printf("5. Se déconnecter\n");
printf("Choix : ");
scanf("%d", &action);

switch (action) {
case 1: deposerArgent(index); break;
case 2: transfererArgent(index); break;
case 3: afficherSolde(index); break;
case 4: supprimerCompte(index); action = 5; break;
}
} while (action != 5);
}
break;
}

} while (choix != 3);

printf("Merci d'avoir utilisé notre système bancaire.\n");
}

int main() {
menuPrincipal();
return 0;
}
