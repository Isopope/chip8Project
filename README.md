# CHIP 8

<div align="center">
<img src="https://i0.wp.com/www.gamecodeur.fr/wp-content/uploads/2022/03/programmation-dun-emulateur-YouTube-Thumbnail.png?resize=350%2C200&ssl=1" height="200px" width="350px"/>
</div>
** Il s'agit d'un emulateur Chip 8 codé en langage C **
<p>
Ce projet est structuré comme suit:
<ol>
<li>le dossiers repertoiresh: il contient tout les fichiers d'en-tetes créés pendant la phase de codage</li>
<li> libprovided: il contient les fichiers d'en-tetes permettant de gerer l'affichage, le son et le clavier, il est bien evidemment fourni avec la lib compilé situé à /libprovided/lib/</li>
<li>les fichier sources .c qui contiennent tout les codes des fonctions des fichiers d'en tetes presents dans repertoiresh</li>
<li>le dossiers /roms: il contient toutes les roms que j'ai eu à testé, vous pouvez les retrouvés sur https://github.com/Timendus/chip8-test-suite</li>
<li>les autres dossiers ou fichiers tels que /bin ou chip8end.* sont des fichiers qui ont été créé à la phase de compilation avec codeBlocks</li>
</ol>

<em>2 principales bibliothèques ont été utilisées:</em>
<ul>
<li>SDL2</li>
<li>(Vous etes libres de l'utiliser ou non)libprovided: il s'agit d'une bibliotheques fourni qui contenais toutes les fonctions nécéssaires pour gérer le son,le clavier, et l'affichage, cette lib s'appui elle meme sur la SDL2</li>
</ul>

</p>


<p>
Ce projet peut encore etre amelioré puisque tout n'est pas parfait(certaines instructions d'opcode bugent  :confused: , vous pouvez vous aidez de sites tels que:
<ul>
<li>http://devernay.free.fr/hacks/chip8/C8TECH10.HTM : il explique le fonctionnement de la chip 8 ainsi que ses caracteristques(en anglais)</li>
<li> https://jeux.developpez.com/tutoriels/programmer-emulateur-console/tutoriel-5-exemples-avec-quelques-instructions/ : il explique et code le chip 8 (bien evidémment vous ne devez regarder le code que si vous bloquez vous-meme sur une partie lors du codage)</li>
<li>http://fredericgoset.ovh/sdl/en/installation.html#:~:text=So%20open%20up%20Code%3A%3A,on%20the%20%22linker%22%20tab.  : pour ceux qui utiliseront codeBlocks , c'est un site qui vous apprendra comment linker des librairies externes notemment la SDL2 içi</li>
</ul>

</p>

Bonne chance et bonne suite dans votre apprentissage du langage C :smile: .