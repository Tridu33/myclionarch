
const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});
rl.question('read arr:', (arr) => {
    let nums = arr.split(" ").map(Number);
    console.log(`The nums is: ${nums}`);
    rl.close();
});