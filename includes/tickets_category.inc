<?php

/**
 * @File ticket_category.inc
 * Provide function access to ticket_category
 */

/**
 * Fetch a ticket_category object.
 *
 * @param $ticket_category_id
 *   Integer specifying the ticket_category id.
 * @param $reset
 *   A boolean indicating that the internal cache should be reset.
 * @return
 *   A fully-loaded $ticket_category object or FALSE if it cannot be loaded.
 *
 * @see ticket_category_load_multiple()
 */
function ticket_category_load($ticket_category_id, $reset = FALSE) {
  $ticket_categorys = ticket_category_load_multiple(array($ticket_category_id), array(), $reset);
  return reset($ticket_categorys);
}

/**
 * Load multiple ticket_categorys based on certain conditions.
 *
 * @param $ticket_cids
 *   An array of ticket_category IDs.
 * @param $conditions
 *   An array of conditions to match against the {ticket_category} table.
 * @param $reset
 *   A boolean indicating that the internal cache should be reset.
 * @return
 *   An array of ticket_category objects, indexed by pid.
 *
 * @see entity_load()
 * @see ticket_category_load()
 */
function ticket_category_load_multiple($ticket_cids = array(), $conditions = array(), $reset = FALSE) {
  return entity_load('ticket_category', $ticket_cids, $conditions, $reset);
}

/**
 * Deletes a ticket_category.
 */
function ticket_category_delete(TicketEntity $ticket_category) {
  $ticket_category->delete();
}

/**
 * Delete multiple ticket_categorys.
 *
 * @param $pids
 *   An array of ticket_category IDs.
 */
function ticket_category_delete_multiple(array $ticket_cids) {
  entity_get_controller('ticket_category')->delete($ticket_cids);
}

/**
 * Create a new ticket_category object.
 */
function ticket_category_create(array $values) {
  return new TicketEntity($values);
}


/**
 * Saves a ticket_category to the database.
 *
 * @param $ticket_category
 *   The ticket_category object.
 */
function ticket_category_save(TicketEntity $ticket_category) {
  return $ticket_category->save();
}



