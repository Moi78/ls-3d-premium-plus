# ls-3d-premium-plus
Défis du moi de Février 2021 sur le merveilleux serveur discord Ceux qui Savent Coder Mais Qu'ont Pas D'Idées. Basé sur Expansion Game Engine

# Installation / Compilation

Pour les utilisateurs windows, pour des questions de simplicités, je vous fait une release avec les binaires.

Les linuxiens eux devront compiler le moteur, l'installer et compiler le projet. Ne vous inquiétez pas il n'est pas difficile à compiler,
armez vous de CMake, installez les dépendances nécessaires et lancez la compilation. ~~Suwako a réussi sous Gentoo, vous réussirez aussi~~. Et n'oubliez pas de
`make install` après la compilation du moteur. (Si vous ne voulez pas compiler vous même le moteur vous pouvez toujours mettre
les binaires qui sont dans `Bins/Linux64/` dans votre `/usr/lib`)

Après vous devrez compiler le projet, encore avec CMake, vous n'aurez pas de dépendances à installer. Après il faudra simplement éxécuter le script
`pack_game.sh` pour qu'il récupère les assets et les binaires fraichement compilés dans un dossier. Après ça, vous pouvez éxécuter le programme ^^
(Il est possible d'en faire un alias et de pouvoir l'éxécuter de n'importe où :eyes:)
