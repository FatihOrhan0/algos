//solution to freecodecamps javascript algorithms course.

function checkCashRegister(price, cash, cid) {
    var change = cash - price;
    var answer = {
        status: "",
        change: []
    }
    var total = 0.00;
    for (let i = 0; i < cid.length; i++) {
        total += cid[i][1];
    }
    if (total == change) {
        answer.status = "CLOSED";
        answer.change = cid;
        return answer;
    }
    var hundred = 0,
        twenty = 0,
        ten = 0,
        five = 0,
        one = 0,
        quarter = 0,
        dime = 0,
        nickel = 0,
        penny = 0;
    while (change > 0) {
        if (change >= 100) {
            while (change >= 100 && cid[8][1] >= 100) {
                if (cid[8][1] >= 100) {
                    hundred++;
                    change -= 100;
                    cid[8][1] -= 100;
                }
            }
        }
        if (change >= 20) {
            while (change >= 20 && cid[7][1] >= 20) {
                if (cid[7][1] >= 20) {
                    twenty++;
                    change -= 20;
                    cid[7][1] -= 20;
                }
            }
        }
        if (change >= 10) {
            while (change >= 10 && cid[6][1] >= 10) {
                if (cid[6][1] >= 10) {
                    ten++;
                    change -= 10;
                    cid[6][1] -= 10;
                }
            }
        }
        if (change >= 5) {
            while (change >= 5 && cid[5][1] >= 5) {
                if (cid[5][1] >= 5) {
                    five++;
                    change -= 5;
                    cid[5][1] -= 5;
                }
            }
        }
        if (change >= 1) {
            while (change >= 1 && cid[4][1] >= 1) {
                if (cid[4][1] >= 1) {
                    one++;
                    change -= 1;
                    cid[4][1] -= 1;
                }
            }
        }
        if (change >= 0.25) {
            while (change >= 0.25 && cid[3][1] >= 0.25) {
                if (cid[3][1] >= 0.25) {
                    quarter++;
                    change -= 0.25;
                    cid[3][1] -= 0.25;
                }
            }
        }
        if (change > 0.10) {
            while (change >= 0.10 && cid[2][1] >= 0.10) {
                if (cid[2][1] >= 0.10) {
                    dime++;
                    change -= 0.10;
                    cid[2][1] -= 0.10;
                }
            }
        }
        if (change >= 0.05) {
            while (change >= 0.05 && cid[1][1] >= 0.05) {
                if (cid[1][1] >= 0.05) {
                    nickel++;
                    change -= 0.05;
                    cid[1][1] -= 0.05;
                }
            }
        }
        if (change >= 0.01) {
            while (change >= 0.01 && cid[0][1] >= 0.01) {
                if (cid[0][1] >= 0.01) {
                    penny++;
                    change -= 0.01;
                    cid[0][1] -= 0.01;
                }
            }
        }
        if (change >= 0.01) {
            answer.status = "INSUFFICIENT_FUNDS";
            break;
        } else {
            if (penny > 0)
                answer.change.push(["PENNY", penny * 0.01]);
            if (nickel > 0)
                answer.change.push(["NICKEL", nickel * 0.05]);
            if (dime > 0)
                answer.change.push(["DIME", dime * 0.10]);
            if (quarter > 0)
                answer.change.push(["QUARTER", quarter * 0.25]);
            if (one > 0)
                answer.change.push(["ONE", one * 1]);
            if (five > 0)
                answer.change.push(["FIVE", five * 5]);
            if (ten > 0)
                answer.change.push(["TEN", ten * 10]);
            if (twenty > 0)
                answer.change.push(["TWENTY", twenty * 20]);
            if (hundred > 0)
                answer.change.push(["ONE HUNDRED", hundred * 100]);
            answer.status = "OPEN";
            break
        }
    }
    console.log(answer);
    return answer;
}

checkCashRegister(19.5, 20, [
    ["PENNY", 1.01],
    ["NICKEL", 2.05],
    ["DIME", 3.1],
    ["QUARTER", 4.25],
    ["ONE", 90],
    ["FIVE", 55],
    ["TEN", 20],
    ["TWENTY", 60],
    ["ONE HUNDRED", 100]
]);