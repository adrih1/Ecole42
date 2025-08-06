# 🌧️ Rainfall

## 📌 Description

**Rainfall** est un projet d'introduction à l'exploitation de binaires de type **ELF-like**.  
Ce projet met l'accent sur la compréhension et l'exploitation de failles simples dans des exécutables Linux, à travers une approche progressive et pédagogique.

## 🧰 Technologies utilisées

- **C** – Langage principal utilisé pour la compilation des binaires vulnérables.
- **Python** – Scripts d'automatisation, d'exploitation ou d'analyse.
- **GDB** – Débogueur utilisé pour l’analyse dynamique des binaires.

## 🎯 Objectifs pédagogiques

- Apprendre à analyser un binaire ELF sous Linux.
- S'initier à l'exploitation de failles telles que les **buffer overflows**.
- Comprendre le fonctionnement de la **pile**, des **registres**, et des protections comme **ASLR** ou **NX**.
- Utiliser des outils tels que **GDB**, **pwndbg**, ou **Python scripts** pour l'exploitation.

## 🧑‍💻 Prérequis

- Connaissances de base en langage C.
- Environnement Linux (ou VM).
- GDB
- Python 3 installé.
- Virtual Box installé

## 🚀 Démarrage rapide


### Cloner le repo

```bash
git clone https://github.com/ton-utilisateur/rainfall.git
cd rainfall
```
### Virtual Box

2. Creer une VM avec le fichier .iso de Rainfall, garder tous les parametres par defaut

![image info](./assets/VirtualBox.png)

Puis lancer la VM, si tout fonctionne vous devriez voir ceci :

![image info](./assets/RainfallHome.png)

### Connecter vous au level0

Login: level0
Mot de passe: level0

Pour passer chaque level vous devez lire le fichier .pass du level au dessus.
Pour le level0, le but est donc d'executer ceci:
```bash
$ cat /home/user/level1/.pass
```

### 🔍 Start hacking !!


## 👥 The Team 

<div style="display: flex; gap: 40px; justify-content: flex-start; align-items: center;">
  <a href="https://github.com/adrih1" style="text-align: center; text-decoration: none; color: inherit;">
    <img src="https://github.com/adrih1.png" width="80" style="border-radius: 50%;" alt="Adrien Hors"/>
    <br/>
    <sub><b>Adrien Hors</b></sub>
  </a>
  <a href="https://github.com/Illouminus" style="text-align: center; text-decoration: none; color: inherit;">
    <img src="https://github.com/Illouminus.png" width="80" style="border-radius: 50%;" alt="Edouard Baillot"/>
    <br/>
    <sub><b>Edouard Baillot</b></sub>
  </a>
</div>


