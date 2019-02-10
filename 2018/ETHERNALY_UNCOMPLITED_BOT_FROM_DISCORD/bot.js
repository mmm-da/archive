const Discord = require('discord.js');
const client = new Discord.Client();
var fs = require('fs');
var wordArr,i,EZH_FACE,t;


fs.readFile("./sound.list", function(err, data) {
    if (err) {
        console.error(err);
    } else {
        str=data.toString();
        wordArr=str.split('.');
    }
});

fs.readFile("./face.dat", function(err, data) {
    if (err) {
        console.error(err);
    } else {
        EZH_FACE=data.toString();
        console.log(EZH_FACE);
    }
});



var prefix ='/';

client.on('ready', () => {
    client.user.setGame('ЕБАЛО ЕЖА НА '+EZH_FACE);
    console.log('Bot ready!');
});

function playSound(message,soundPath) {
    if (message.member.voiceChannel) {
      message.member.voiceChannel.join()
        .then(connection => {
          connection.playFile(soundPath);
        })
    }
  }


function faceSet(message,t,) {
    EZH_FACE=t;
    fs.writeFile("./face.dat", EZH_FACE, function(err) {
    if(err) {
        return console.log(err);
    }

    console.log("The file was saved!");
})
  }




    client.on('message', message => {
        for(i=1;i<wordArr.lenght;i++){
          if(message.content==prefix+wordArr[i]){
            playSound(message,'./sounds/'+wordArr[i]+'.mp3');
          }
        }
        if(message.content==prefix+'leave'){
          if (message.member.voiceChannel) {
            message.member.voiceChannel.leave();
          }
        }
      }
    );

   client.on('message', message => {
    if(message.content==prefix+'статус ебала'){
      message.reply('текущий уровень ебала Ежа на '+EZH_FACE);
  }});

  client.on('message', message => {
      for(i=0;i<=10;i++){
           if(message.content==prefix+'ебало на '+i){
      if(message.author.username!='Xzibit322'){
     message.reply('этот параметр может изменять только Семен');
      }
      if(message.author.username=='Xzibit322'){
     faceSet(message,i);
      client.user.setGame('ЕБАЛО ЕЖА НА '+EZH_FACE);
        message.reply('текущий уровень ебала на '+EZH_FACE);
      }
      }
      }
   });



client.on('message', message => {
  if (message.content == prefix+'help') {
    message.reply({embed: {
  color: 3447003,
  author: {
    name: client.user.username,
    icon_url: client.user.avatarURL
  },
  title: "СПИСОК КОМАНД",
  description: "НАДА СЪЕБЫВАТЬ ОТСЮДА, Я КАМЕНЬЩИК РАБОТАЮ БЕЗ ВЫХОДНЫХ МОЙ ТЕЛЕФОН МЕГАФОН",
  fields: [{name: prefix+"yeay",
            value:"."},
    {name: prefix+"help",
             value:"помогает даунам журналистам разобратся в командах бота"},
    {name: prefix+"ttos",
     value:"."},
    {name: prefix+"bass",
     value:"."},
     {name: prefix+"slap,f,300,dm,next",
      value:"ты ошибся командой клуб любителей мемов 2 команды выше"},
      {name: prefix+"why",
       value:"we still here? just to suffer?"},
    {name: prefix+"leave",
      value:"изгоняет темного фантома из вашего мира "}
  ],
}})}});

client.login('');
