function sym(args) {

    if (arguments.length == 0) {
        return [];
    } else if (arguments.length == 1) {
        return arguments[0];
    }
    let answer = [];
    var processed = 0;
    while (processed < arguments.length - 1) {
        for (var i = 0; i < arguments[processed].length; i++) {
            for (var j = 0; j < arguments[processed + 1].length; j++) {
                if (arguments[processed][i] == arguments[processed + 1][j]) {
                    arguments[processed].splice(i, 1);
                    arguments[processed + 1].splice(j, 1);
                    i--;
                    continue;
                }
            }
        }
        processed++;
    }
    for (var i = 0; i < arguments.length; i++) {
        for (var j = 0; j < arguments[i].length; j++)
            answer.push(arguments[i][j]);
    }
    return answer;
}

let answer = sym([1, 2, 3], [5, 2, 1, 4], [2, 6, 8]);
//answer is [ 3, 5, 4, 2, 6, 8 ].