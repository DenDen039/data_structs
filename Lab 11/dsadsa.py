class Warrior:
    def __init__(self):
        self.health = 50
        self.power = 5
        self.is_alive = True
    def attack(self,enemy):
        if not enemy.is_alive or not self.is_alive:
            return
        enemy.health -= self.power
        if enemy.health <= 0:
            enemy.is_alive = False
class Knight(Warrior):
    def __init__(self):
        self.health = 50
        self.power = 7
        self.is_alive = True
    def attack(self,enemy):
        if not enemy.is_alive or not self.is_alive:
            return
        enemy.health -= self.power
        if enemy.health <= 0:
            enemy.is_alive = False

def fight(unit_1, unit_2):
    while unit_1.is_alive and unit_2.is_alive:
        unit_1.attack(unit_2)
        unit_2.attack(unit_1)
    return unit_1.is_alive

if __name__ == '__main__':
    #These "asserts" using only for self-checking and not necessary for auto-testing

    chuck = Warrior()
    bruce = Warrior()
    carl = Knight()
    dave = Warrior()
    mark = Warrior()

    assert fight(chuck, bruce) == True
    assert fight(dave, carl) == False
    assert chuck.is_alive == True
    assert bruce.is_alive == False
    assert carl.is_alive == True
    assert dave.is_alive == False
    assert fight(carl, mark) == False
    assert carl.is_alive == False

    print("Coding complete? Let's try tests!")
