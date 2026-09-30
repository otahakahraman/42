import random

def gen_player_achievements() -> None:
    all_achievements={'Crafting Genius', 'Strategist', 'World Savior', 'Speed Runner', 'Survivor',
                          'Master Explorer', 'Treasure Hunter', 'Unstoppable', 'Hidden Path Finder','First Steps', 'Collector Supreme', 
                          'Untouchable', 'Sharp Mind', 'Boss Slayer'}
    alice=set()
    for _ in range(random.randint(1,14)):
        alice.add(random.choice(list(all_achievements)))
    bob=set()
    for _ in range(random.randint(1,14)):
        bob.add(random.choice(list(all_achievements)))
    charlie=set()
    for _ in range(random.randint(1,14)):
        charlie.add(random.choice(list(all_achievements)))
    dylan=set()
    for _ in range(random.randint(1,14)):
        dylan.add(random.choice(list(all_achievements)))
    distinct=set.union(alice ,bob,charlie,dylan)
    common=set.intersection(alice, bob, charlie, dylan)
    unique_alice=alice.difference(bob, charlie, dylan)
    unique_bob=bob.difference(alice, charlie, dylan)
    unique_charlie=charlie.difference(alice, bob, dylan)
    unique_dylan=dylan.difference(alice, bob, charlie)

    print(f"Player Alice: {alice}")
    print(f"Player Bob: {bob}")
    print(f"Player Charlie: {charlie}")
    print(f"Player Dylan: {dylan}\n")
    print(f"All distinct achievements: {distinct}\n")
    print(f"Common achievements: {common}\n")
    print(f"Only Alice has: {unique_alice}")
    print(f"Only Bob has: {unique_bob}")
    print(f"Only Charlie has: {unique_charlie}")
    print(f"Only Dylan has: {unique_dylan}\n")
    print(f"Alice is missing: {list(all_achievements-alice)}")
    print(f"Bob is missing: {list(all_achievements-bob)}")
    print(f"Charlie is missing: {list(all_achievements-charlie)}")
    print(f"Dylan is missing: {list(all_achievements-dylan)}")

def main() -> None:
    print("=== Achievement Tracker System ===\n")
    gen_player_achievements()

if __name__ == "__main__":
    main()