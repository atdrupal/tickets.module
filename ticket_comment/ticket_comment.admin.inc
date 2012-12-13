<?php
/**
 * @file lgentity.admin.inc
 */

function ticket_comment_form($form, &$form_state, $entity, $op = 'edit', $entity_type = 'ticket_comment', $ticket) {
  if (!$entity->type) $entity->type = $entity_type;
  
  $form_state['ticket_comment'] = $entity;
  $form_state['ticket_id'] = $ticket->ticket_id;
  $form_state['ticket'] = $ticket;
  $language = empty($ticket->language) ? 'und' : $ticket->language;
  $category = $ticket->ticket_entity_reference_category[$language][0]['target_id'];
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
    '#prefix' => '<div class="submit">',
    '#suffix' => '</div>'
  );
  return $form;
}

/**
 * Submit handler for machine-recommend entity.
 */
function ticket_comment_form_submit($form, &$form_state) {

  $ticket_comment = $form_state['ticket_comment'];
  $ticket = $form_state['ticket'];
  $ticket_category = $form_state['ticket_category'];
  $ticket_comment->ticket_id = $form_state['ticket_id'];
  entity_form_submit_build_entity('ticket_comment', $ticket_comment, $form, $form_state);
  $ticket_comment->save($ticket_comment);
  
  //Update ticket and ticket category
  $ticket_category->ticket_category_importance = $ticket_comment->ticket_category_importance;
  $ticket_category->ticket_category_state = $ticket_comment->ticket_category_state;
  $ticket->ticket_entity_reference_user = $ticket_comment->ticket_entity_reference_user;
  
  $ticket_category->save($ticket_category);
  $ticket->save($ticket);
}