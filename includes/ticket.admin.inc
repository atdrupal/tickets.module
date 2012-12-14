<?php
/**
 * @file lgentity.admin.inc
 */

function ticket_form($form, &$form_state, $entity, $op = 'edit', $entity_type) {
  if (!$entity->type) $entity->type = $entity_type;

  // Attach fields
  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#default_value' => isset($entity->title) ? $entity->title : '',
    '#maxlength' => 255,
    '#required' => TRUE,
    '#weight' => -5,
  );
//  $langcode = entity_language($entity_type, $entity);
//  // Simply use default language
//  $form['language'] = array(
//    '#type' => 'value',
//    '#value' => $langcode,
//  );
  field_attach_form($entity_type, $entity, $form, $form_state, $langcode);

  $form['actions']['#weight'] = 100;
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  return $form;
}

/**
 * Submit handler for machine-recommend entity.
 */
function ticket_form_submit($form, &$form_state) {
  $entity = entity_ui_form_submit_build_entity($form, $form_state);
  $entity->save();
  $form_state['redirect'] = "admin/structure/tickets";
}


//function ticket_page_edit($ticket) {
//  return drupal_get_form('ticket_form',$ticket, 'edit', 'ticket');
//}
//
//
///**
// * Form callback wrapper: create or edit a ticket.
// *
// * @param $ticket
// *   The ticket object being edited by this form.
// *
// * @see ticket_edit_form()
// */
//function ticket_form_wrapper($ticket) {
//  // Add the breadcrumb for the form's location.
////  ticket_set_breadcrumb();
//  return drupal_get_form('ticket_edit_form', $ticket);
//}
//
//
///**
// * Form callback: create or edit a ticket.
// */
//function ticket_edit_form($form, &$form_state, $entity) {
//  $entity_type = 'ticket';
//  
//  $form['#entity_type'] = $entity_type;
//  // Attach fields
//  $form['title'] = array(
//    '#type' => 'textfield',
//    '#title' => t('Title'),
//    '#default_value' => isset($entity->title) ? $entity->title : '',
//    '#maxlength' => 255,
//    '#required' => TRUE,
//    '#weight' => -5,
//  );
//  $langcode = entity_language($entity_type, $entity);
//  // Simply use default language
//  
//  $form_state['ticket'] = $entity;
//  field_attach_form($entity_type, $entity, $form, $form_state, $langcode);
//
//  $form['actions']['#weight'] = 100;
//  $form['actions']['submit'] = array(
//    '#type' => 'submit',
//    '#value' => t('Save'),
//  );
//
//  return $form;
//}
//
///**
// * Form API validate callback for the ticket form
// */
//function ticket_edit_form_validate(&$form, &$form_state) {
//  $ticket = $form_state['ticket'];
//  
//  // Notify field widgets to validate their data.
//  field_attach_form_validate('ticket', $ticket, $form, $form_state);
//}
//
//
///**
// * Form API submit callback for the ticket form
// */
//function ticket_edit_form_submit(&$form, &$form_state) {
//  $ticket = entity_ui_controller('ticket')->entityFormSubmitBuildEntity($form, $form_state);
//  // Save the ticket and go back to the list of ticket
//  $ticket->save();
//}
//
