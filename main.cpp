#include <iostream>
#include "Account.h"

int main() {

    auto* marioRossi = new Account ("Mario Rossi", 0, 1732.16, 1000);
    auto* luigiBianchiDitta = new Account ("DITTA EDILE di Luigi Bianchi", 1, 9814.95, 10000);

    marioRossi->outgoingTransaction(luigiBianchiDitta, "Lavori di ristrutturazione cucina", 579.00);

    return 0;
}
