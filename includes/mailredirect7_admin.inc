<?php

/**
 * @file
 * This file is for the admin part of the mailredirect7 module
 *
 */

/**
 * Return an admin form
 */
function mailredirect7_admin() {
  $return = '';

  $return = drupal_get_form('mailredirect7_admin_form');

  return $return;
}

/**
 * Hook_form
 */
function mailredirect7_admin_form() {
  $form = array();

  //List of emailaddresses
  $form['mailredirect7_to_list'] = array(
    '#title' => t('To who will the redirected mail be send'),
    '#description' => t('Give a list of emailaddresses. This emailaddresses will be used to redirect the mail to. To give more emailaddresses use a comma to separate.'),
    '#type' => 'textfield',
    '#default_value' => variable_get( 'mailredirect7_to_list', '' ),
  );

  $fieldset_id = 'mailredirect7_admin_fieldset';

  $form[$fieldset_id] = array(
    '#type' => 'fieldset',
    '#title' => 'Modules',
  );

  //Get the modules which implements hook_mail
  $modules = mailredirect7_getmodules();

  $form[$fieldset_id]['mailredirect7_modules'] = array(
    '#type' => 'checkboxes',
    '#options' => $modules,
    '#default_value' => variable_get( 'mailredirect7_modules', array( ) ), //In the viable_get are the modules saved which are selected by the administrator
  );

  $form['mailredirect7_subjectprefix'] = array(
    '#type' => 'radios',
    '#title' => 'Subjectprefix',
    '#description' => t('If this is filled, this will be prefixed at the beginning of the subject. E.G. (123) Welcome new user.'),
    '#type' => 'textfield',
    '#default_value' => variable_get('mailredirect7_subjectprefix', ''),
  );

  //Return it as a system_settings_form
  return system_settings_form( $form );
}