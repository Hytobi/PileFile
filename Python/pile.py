class Pile :
    '''Definition d'une pile - structure de données LIFO (Last In First Out)
    '''

    def __init__(self) : 
        '''Pile -> Pile
        construit une pile vide
        '''
        # basée sur une pile
        self.__les_elts = list()
        
    
    def empiler(self,elt) :
        '''(modif) Pile, Objet -> Rien
        ajoute un élément au sommet de la pile.
        '''
        self.__les_elts.append(elt)
            
    def est_vide(self) : 
        '''Pile -> Boolean
        teste si la pile est vide. '''
        return len(self.__les_elts) == 0
  
    def sommet(self) : 
        '''Pile -> Objet
        retourne l'élément au sommet de la pile.
        '''
        assert not self.est_vide()
        return self.__les_elts[-1] 
        
    def depiler(self) : 
        '''(modif) Pile -> Objet
        enlève l'élément au sommet de la pile.
        ''' 
        assert not self.est_vide()
        elt = self.__les_elts[-1] 
        del(self.__les_elts[-1])
        return elt

# Test la pile
def pair_impair(pileA):
    ''' Prend une pile et met une succession de pair impaire'''
    p = Pile()
    i = Pile()
    for elem in pileA:
        if elem % 2 :
            p.empiler(pileA.depile())
        else :
            i.empiler(pileA.depile())

    while not p.est_vide() or not i.est_vide():
        pileA.empiler(p.depile())
        pileA.empiler(i.depile())
    if i.est_vide():
        while not p.est_vide() :
            pileA.empiler(p.depile())
    else :
        while not i.est_vide():
            pileA.empiler(i.depile())
# fin de la classe Pile
   