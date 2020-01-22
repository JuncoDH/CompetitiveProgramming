var pos;
var rango;
var nuevadir;
var longdisparo;

async function persigue(tank, angulo){
	await tank.drive(angulo, 20);

	return 0;
}

async function disparo(tank){
  var aux;
  longdisparo=await tank.scan(nuevadir, 100);
	while( longdisparo!= 0){
		rango = rango - 100;
		if(rango < 100)rango = 100;
		await tank.shoot(nuevadir, longdisparo+10);
		await persigue(tank, nuevadir);
		nuevadir = (nuevadir + 355) % 360;
    longdisparo=await tank.scan(nuevadir, 100);
	}
  aux=nuevadir+20;
  rango=rango+100;
  if(await tank.scan(aux,50)!=0){
    nuevadir=aux;
    return 1;
  }
  aux=nuevadir-20;
  if(await tank.scan(aux,50)!=0){
    nuevadir=aux;
    return -1;
  }

	return 0;
}


async function main(tank) {
	nuevadir=0;
	longdisparo = 400;
  await tank.drive(0, 50);
  var res,giro;
  rango=100;
  var turn=1;
  var tmp=1;
  giro=0;

  while(true){
    await tank.drive(giro,50);
    if(await tank.scan(giro,50)!=0){
      nuevadir=giro;
      turn =await disparo(tank);
      tmp=1;
      while(turn!=0){
        tmp=turn;
        turn= await disparo(tank);

      }

      turn=tmp;
      giro=nuevadir;
    }



    giro=(giro + (10*turn))%360;

  }

}

