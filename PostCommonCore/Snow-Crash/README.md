# Snow Crash

Welcome to the Snow Crash project, a challenging exercise proposed by 42 and led with [Edouard Baillot](https://github.com/Illouminus), which allowed us to deepen our knowledge in cybersecurity, cryptography, and hacking.

---

## Table des Matières

- [Introduction](#introduction)
- [What We Did](#what-we-did)
- [What We Learned](#what-we-learned)
- [Prérequis](#prérequis)
- [Structure du Projet](#structure-du-projet)
- [Ressources](#ressources)
- [Auteurs](#auteurs)

---

## Introduction

Le projet **Snow Crash** met à l’épreuve les compétences en sécurité informatique au travers de plusieurs niveaux impliquant l’exploitation de vulnérabilités, la résolution de défis cryptographiques et l'analyse de systèmes. Voici un retour sur ce que j'ai réalisé et appris durant ce projet.

## Ce que j'ai fait

1. **Analyse de vulnérabilités** : J'ai exploré des binaires et des scripts pour identifier des failles potentielles.
2. **Exploitations réussies** :
   - Lecture de fichiers protégés par des mécanismes d'accès restreints.
   - Injection de code dans des programmes pour détourner leur exécution.
   - Contournement de protections mémoire via des exploits.
3. **Debugging intensif** : Utilisation de débogueurs comme `gdb` et d'outils comme `strace` pour comprendre et manipuler les comportements des programmes.

## Ce que j'ai appris

1. **Approfondissement des concepts de sécurité** :
   - Comprendre les vulnérabilités courantes comme les scripts SUID, ou encore les injections.
   - Analyse de flux TCP
   - Modification du PATH
   - Exploit script perl
   - Exploitation du CRON
   - Injectuon via des variables d'environnements ou des fonctions
   - Bypass grâce à un lien symbolique

2. **Utilisation d'outils de pentesting** :
   - `ltrace` pour suivre les appels système.


3. **Méthodologie de résolution de problèmes** :
   - Décomposer un problème complexe en étapes simples.
   - Tester systématiquement des hypothèses pour identifier des solutions efficaces.

4. **Cryptographie** : Découverte et exploitation des failles dans des algorithmes ou mécanismes mal implémentés.

## Prérequis

Pour réussir ce projet, une bonne maîtrise des concepts suivants est nécessaire :

- Programmation en C et Python.
- Connaissances de base en systèmes Unix/Linux.
- Débogage de programmes (outils comme `gdb`, `valgrind`).
- Connaissance des bases de la mémoire et des systèmes d'exploitation.

## Structure du Projet

Le projet est organisé en niveaux croissants de difficulté :

- **level00** : Introduction et découverte de vulnérabilités simples.
- **level01** à **levelXX** : Chaque niveau propose un défi unique, allant de la manipulation de fichiers à l’exploitation binaire avancée.

Chaque niveau comprend des fichiers à analyser et un environnement pour tester les solutions.
