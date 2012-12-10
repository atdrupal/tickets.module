<?php
/**
 * @file lgentity.admin.inc
 */

function ticket_comments_form($form, &$form_state, $entity, $op = 'edit', $entity_type = 'ticket_comments', $ticket) {
  if (!$entity->type) $entity->type = $entity_type;
  
  $form_state['ticket_comments'] = $entity;
  $form_state['ticket_id'] = $ticket->ticket_id;
  $form_state['ticket'] = $ticket;
  

  $category = $ticket->ticket_entity_reference_category[LANGUAGE_NONE][0]['target_id'];
  $ticket_category = ticket_category_load($category);
  $entity->ticket_category_importance = $ticket_category->ticket_category_importance;
  $entity->ticket_category_state = $ticket_category->ticket_category_state;
  $entity->ticket_entity_reference_user = $ticket->ticket_entity_reference_user;

  $form_state['ticket_category'] = $ticket_category;
  field_attach_form($entity_type, $entity, $form, $form_state);
  
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
function ticket_comments_form_submit($form, &$form_state) {

  $ticket_comments = $form_state['ticket_comments'];
  $ticket = $form_state['ticket'];
  $ticket_category = $form_state['ticket_category'];
  $ticket_comments->ticket_id = $form_state['ticket_id'];
  entity_form_submit_build_entity('ticket_comments', $ticket_comments, $form, $form_state);
  $ticket_comments->save($ticket_comments);
  
  //Update ticket and ticket category
  $ticket_category->ticket_category_importance = $ticket_comments->ticket_category_importance;
  $ticket_category->ticket_category_state = $ticket_comments->ticket_category_state;
  $ticket->ticket_entity_reference_user = $ticket_comments->ticket_entity_reference_user;
  
  $ticket_category->save($ticket_category);
  $ticket->save($ticket);
  

//      $form_state['redirect'] = "admin/structure/ticket_commentss";

//  if (isset($entity->field_ref_lesson[LANGUAGE_NONE][0]['target_id'])) {
//    $form_state['redirect'] = "node/{$entity->field_ref_lesson[LANGUAGE_NONE][0]['target_id']}";
//    $form_state['redirect'] = "admin/structure/ticket_commentss";
//  }
//  else {
//    $form_state['redirect'] = 'admin/structure/langgo/machine/recommend';
//  }
}