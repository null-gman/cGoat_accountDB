//compile main c files

//node compileMain.js

const { exec } = require('child_process');
const files = [" main.c"];

files.push("./setRegMainPath.c");
files.push("./myLibs/print/_print.c");
files.push("./myLibs/win32Funs/_win32Funs.c");
files.push("./myLibs/utilities/_utilities.c");
files.push("./myLibs/fsFuns/_fsFuns.c");
files.push("./myLibs/inputFuns/_inputFuns.c");
files.push("./myLibs/myStrFuns/_myStrFuns.c");


files.push("./myLibs/program_methods/startMethods.c");
files.push("./myLibs/program_methods/checkDB.c");
files.push("./sqlite3Lib/sqlite3.c");

////////////////////////////////////
let fullCommand = "gcc -o app.exe";
function setGcc(files) {


  for (let file of files) {
    fullCommand += " " + file;
  }
  // fullCommand += " -L. sqlite3Lib/sqlite3.dll" ;
  return fullCommand;
}

function execFun() {
  let cmdCommnd = setGcc(files);
  // console.log(`command : \'${cmdCommnd}\'\n\n`);
  console.log(`command : \'runing\'\n\n`);
  exec(cmdCommnd, (error) => {
    if (error) {
      console.error(`\nexec error:\n -> ${error} ~~END\n\n`);
      return;
    }

    console.log(`end of exec .`);
  });
}

execFun();
