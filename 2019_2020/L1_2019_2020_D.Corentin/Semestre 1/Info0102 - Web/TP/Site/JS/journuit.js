function changermode() {
  var color = document.getElementById('mode').style.color;

  var backgroundColor = document.getElementById('mode').style.backgroundColor;


  if (color == "black" && backgroundColor == "white") {
    document.getElementById('mode').style.color = "white";
    document.getElementById('mode').style.backgroundColor = "#10171e";
    document.getElementById("nommode").style.color = "black";
    document.getElementById("nommode").style.backgroundColor = "white";
    document.getElementById("nommode").value = "Jour";
    document.getElementById("chat_embed").src = "https://www.twitch.tv/embed/datgoldhawk/chat?darkpopout=";
    document.getElementById("textpopup").style.color = "black";
    document.getElementById("textpopup").style.backgroundColor = "white";


  } else {
    document.getElementById('mode').style.color = "black";
    document.getElementById('mode').style.backgroundColor = "white";
    document.getElementById("nommode").style.color = "white";
    document.getElementById("nommode").style.backgroundColor = "#222f3e";
    document.getElementById("nommode").value = "Nuit";
    document.getElementById("chat_embed").src = "https://www.twitch.tv/embed/datgoldhawk/chat?popout=";
    document.getElementById("textpopup").style.color = "black";
    document.getElementById("textpopup").style.backgroundColor = "white";


  }
}
