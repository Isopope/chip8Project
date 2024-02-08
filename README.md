# CHIP 8

<div align="center">
<img src="https://www.google.com/url?sa=i&url=https%3A%2F%2Fwww.gamecodeur.fr%2Fnouvelle-master-class-programmation-dun-emulateur-de-chip8-en-c-avec-la-sdl2%2F&psig=AOvVaw3814tQ_U2aw1G32mDEuMVp&ust=1707488965394000&source=images&cd=vfe&opi=89978449&ved=0CBIQjRxqFwoTCLiQxKD6m4QDFQAAAAAdAAAAABAE" width="100px"/>
</div>
**Il s'agit d'un emulateur Chip 8 codé en langage C **
<p>
Ce projet est structuré comme suit:
    - le dossiers repertoiresh: il contitent tout les fichiers d'en-tetes créés pendant la phase de codage
    - libprovided: il contient les fichiers d'en-tetes permettant de gerer l'affichage, le son et le clavier, il est bien evidemment fourni avec la lib compilé situé à libprovided/lib/
    - les fichier sources .c qui contiennent tout les code des fonctions des fichiers d'en tetes presents dans repertoiresh
    - le dossiers /roms: il contient toutes les roms que j'ai eu a testé, vous pouvez les retoruvé sur https://github.com/Timendus/chip8-test-suite
    - les autres dossiers ou fichiers tels que /bin ou chip8end.* sont des fichiers qui ont été créé à la phase de compilation avec codeBlocks
2 principales bibliothèques ont été utilisées:
    - SDL2
    - (Vous etes libres de l'utiliser ou non)libprovided: il s'agit d'une bibliotheques fourni qui contenais toutes les fonctions nécéssaires pour gérer le son,le clavier, et l'affichage, cette lib s'appui elle meme sur la SDL2

</p>


<p>
Ce projet peut encore etre amelioré puisque tout n'est pas parfait(certaines instructions d'opcode bug :), vous pouvez vous aidez de sites tels que:
    * http://devernay.free.fr/hacks/chip8/C8TECH10.HTM : il explique le fonctionnement de la chip 8 ainsi que ses caracteristques(en anglais)
    * https://jeux.developpez.com/tutoriels/programmer-emulateur-console/tutoriel-5-exemples-avec-quelques-instructions/ : il explique et code le chip 8 (bien evidémment vous devez regarder le code que si vous bloquez vous-meme sur une partie lors du codage)
    * http://fredericgoset.ovh/sdl/en/installation.html#:~:text=So%20open%20up%20Code%3A%3A,on%20the%20%22linker%22%20tab.  : pour ceux qui utiliseront codeBlocks , c'est un site qui vous apprendra comment linker des librairies externes notemment la SDL2 içi

</p>

Bonne chance et bonne suite dans votre apprentissage du langage C :smile: .