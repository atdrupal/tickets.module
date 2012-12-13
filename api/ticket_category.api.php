
<?php

/**
 * @file
 * This file contains no working PHP code; it exists to provide additional
 * documentation for doxygen as well as to document hooks in the standard
 * Drupal manner.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
* Act on profiles being loaded from the database.
*
* This hook is invoked during profile loading, which is handled by
* entity_load(), via the EntityCRUDController.
*
* @param $entities
*   An array of ticket_category entities being loaded, keyed by id.
*
* @see hook_entity_load()
*/
function hook_ticket_category_load($entities) {
  $result = db_query('SELECT ticket_cid, foo FROM {mytable} WHERE ticket_cid IN(:ids)', array(':ids' => array_keys($entities)));
  foreach ($result as $record) {
    $entities[$record->ticket_cid]->foo = $record->foo;
  }
}

/**
* Respond when a profile is inserted.
*
* This hook is invoked after the profile is inserted into the database.
*
* @param profile
*   The profile that is being inserted.
*
* @see hook_entity_insert()
*/
function hook_ticket_category_insert($ticket_category) {
  db_insert('mytable')
    ->fields(array(
      'ticket_cid' => $ticket_category->ticket_cid,
      'extra' => $ticket_category->extra,
    ))
    ->execute();
}

/**
* Act on a profile being inserted or updated.
*
* This hook is invoked before the profile is saved to the database.
*
* @param $ticket_category
*   The profile that is being inserted or updated.
*
* @see hook_entity_presave()
*/
function hook_ticket_category_presave($ticket_category) {
  $ticket_category->extra = 'foo';
}

/**
* Respond to a profile being updated.
*
* This hook is invoked after the profile has been updated in the database.
*
* @param $ticket_category
*   The $ticket_category that is being updated.
*
* @see hook_entity_update()
*/
function hook_ticket_category_update($ticket_category) {
  db_update('mytable')
    ->fields(array('extra' => $ticket_category->extra))
    ->condition('ticket_cid', $ticket_category->ticket_cid)
    ->execute();
}

/**
* Respond to profile deletion.
*
* This hook is invoked after the profile has been removed from the database.
*
* @param $ticket_category
*   The profile that is being deleted.
*
* @see hook_entity_delete()
*/
function hook_ticket_category_delete($ticket_category) {
  db_delete('mytable')
    ->condition('ticket_cid', $ticket_category->ticket_cid)
    ->execute();
}

/**
* Act on a profile that is being assembled before rendering.
*
* @param $ticket_category
*   The profile entity.
* @param $view_mode
*   The view mode the profile is rendered in.
* @param $langcode
*   The language code used for rendering.
*
* The module may add elements to $ticket_category->content prior to rendering. The
* structure of $ticket_category->content is a renderable array as expected by
* drupal_render().
*
* @see hook_entity_prepare_view()
* @see hook_entity_view()
*/
function hook_ticket_category_view($ticket_category, $view_mode, $langcode) {
  $ticket_category->content['my_additional_field'] = array(
    '#markup' => $additional_field,
    '#weight' => 10,
    '#theme' => 'mymodule_my_additional_field',
  );
}

/**
* Alter the results of entity_view() for profiles.
*
* @param $build
*   A renderable array representing the profile content.
*
* This hook is called after the content has been assembled in a structured
* array and may be used for doing processing which requires that the complete
* profile content structure has been built.
*
* If the module wishes to act on the rendered HTML of the profile rather than
* the structured content array, it may use this hook to add a #post_render
* callback. Alternatively, it could also implement hook_preprocess_ticket_category().
* See drupal_render() and theme() documentation respectively for details.
*
* @see hook_entity_view_alter()
*/
function hook_ticket_category_view_alter($build) {
  if ($build['#view_mode'] == 'full' && isset($build['an_additional_field'])) {
    // Change its weight.
    $build['an_additional_field']['#weight'] = -10;

    // Add a #post_render callback to act on the rendered HTML of the entity.
    $build['#post_render'][] = 'my_module_post_render';
  }
}


