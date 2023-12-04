#include "headers/UserRepository.h"
#include "headers/UserManager.h"

using namespace entity;

int main() {
    UserRepository userRepository("../data/repos.txt");

    std::vector<User> users = userRepository.getAll();
    userRepository.add(User(21, "Tolya", "Post", "grtw"));

    userRepository.remote(User(31, "Surik", "surikat", "coolpass"));

    userRepository.update(User(1, "Nikolay", "kolya", "superpass"));

    User user = userRepository.getById(1);

    User user2 = userRepository.getByLogin("Post");

    UserManager userManager(userRepository);

    userManager.signIn(User(1, "Nikolay", "kolya", "superpass"));

    userManager.signIn(User(21, "Tolya", "Post", "grtw"));

    userManager.signOut(User(1, "Nikolay", "kolya", "superpass"));

    userManager.signIn(User(21, "Tolya", "Post", "grtw"));

    userManager.signOut(User(21, "Tolya", "Post", "grtw"));

    userManager.signIn(User(32, "Tolya", "kolya", "superpass"));

    return 0;
}
