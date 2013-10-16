<?php

/**
 * @file
 * This file is dedicated to test the module. You can see it in action ;-)
 */

/**
 *
 * @global type $user
 * @return array form definition
 */
function mailredirect7_test_form() {
  global $user;
  $form = array( );

  //check if the mailredirect7 module  is selected on the admin page
  $mailredirect7modules = variable_get( 'mailredirect7_modules', array( ) );
  if (isset($mailredirect7modules['mailredirect7']) and $mailredirect7modules['mailredirect7'] == 'mailredirect7') {

    //To will will be send the  testmail
    $form['to'] = array(
      '#title' => 'Emailaddress',
      '#description' => t('Give a emailaddress. If the mailredirect7 module is selected on the admin page, this email will not be send to the mail aboven.'),
      '#type' => 'textfield',
      '#default_value' => $user->mail,
    );

    $form['message'] = array(
      '#type' => 'textarea',
      '#title' => t('Message'),
      '#description' => t('This will be the message.'),
      '#required' => TRUE,
      '#default_value' => 'Some test text',
    );

    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => 'Send the mail'
    );
  }
  else{
    //The mailredirect7 modules is not selected on the admin page
    $form['markup'] = array(
      '#markup' => t('The mailredirect7 module is not selected on the adminpage. Enable it !link', array(
        '!link' => l(t('here'), 'admin/settings/mailredirect7')
      )),
    );
  }

  return $form;
}

function mailredirect7_test_form_validate(&$form, &$form_state) {
  if ( valid_email_address($form_state['values']['to']) !== TRUE) {
    form_set_error('to', t('Not a valid emailaddress.'));
  }
}

function mailredirect7_test_form_submit(&$form, &$form_state) {
  drupal_mail('mailredirect7', 'test', $form_state['values']['to'], '', $form_state['values']);
  drupal_set_message(t('Testmail was send successfully!'));
}