function validation(event) {

  if (info.validity.valueMissing) {
    event.preventDefault();
    missInfo.textContent = 'Prénom manquant';
    missInfo.style.color = 'red';
    info.style.backgroundColor = 'red';

  }
  if (email.validity.valueMissing) {
    event.preventDefault();
    missEmail.textContent = 'Email manquant';
    missEmail.style.color = 'red';
    email.style.backgroundColor = 'red';

  } else if (emailValid.test(email.value) == false) {
    event.preventDefault();
    missEmail.textContent = 'Format email incorrect';
    missEmail.style.color = 'orange';
    email.style.backgroundColor = 'orange';
  }
  if (msg.validity.valueMissing) {
    event.preventDefault();
    missMSG.textContent = 'Message manquant';
    missMSG.style.color = 'red';
    msg.style.backgroundColor = 'red';

  }

  if (tel.validity.valueMissing) {
    event.preventDefault();
    missTel.textContent = 'Numéro de téléphone manquant';
    missTel.style.color = 'red';
    tel.style.backgroundColor = 'red';

  } else if (telValid.test(tel.value) == false) {
    event.preventDefault();
    missTel.textContent = 'Numéro de téléphone inccorect';
    missTel.style.color = 'orange';
    tel.style.backgroundColor = 'orange';
  }
  if (telValid.test(tel.value) == true){
    event.preventDefault();
    missTel.textContent = '';
    tel.style.backgroundColor = 'white';

  }
  if (emailValid.test(email.value) == true){
    event.preventDefault();
    missEmail.textContent = '';
    email.style.backgroundColor = 'white';

  }
if(document.form.textarea.lenght==0| document.form.textarea==NULL){
  alert('vide');
}

  if (!tel.validity.valueMissing && !tel.validity.valueMissing && !info.validity.valueMissing && telValid.test(tel.value) == true && emailValid.test(email.value) == true) {


    alert('Votre message a bien été envoyé');

  }

}
