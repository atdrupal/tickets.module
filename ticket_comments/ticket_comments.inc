<?php

/**
 * @File ticket_comments.inc
 * Provide function access to ticket_comments
 */

/**
 * Fetch a ticket_comments object.
 *
 * @param $ticket_comments_id
 *   Integer specifying the ticket_comments id.
 * @param $reset
 *   A boolean indicating that the internal cache should be reset.
 * @return
 *   A fully-loaded $ticket_comments object or FALSE if it cannot be loaded.
 *
 * @see ticket_comments_load_multiple()
 */
function ticket_comments_load($ticket_comments_id, $reset = FALSE) {
  $ticket_comments = ticket_comments_load_multiple(array($ticket_comments_id), array(), $reset);
  return reset($ticket_comments);
}

/**
 * Load multiple ticket_comments based on certain conditions.
 *
 * @param $ticket_comments_ids
 *   An array of ticket_comments IDs.
 * @param $conditions
 *   An array of conditions to match against the {ticket_comments} table.
 * @param $reset
 *   A boolean indicating that the internal cache should be reset.
 * @return
 *   An array of ticket_comments objects, indexed by pid.
 *
 * @see entity_load()
 * @see ticket_comments_load()
 */
function ticket_comments_load_multiple($ticket_comments_ids = array(), $conditions = array(), $reset = FALSE) {
  return entity_load('ticket_comments', $ticket_comments_ids, $conditions, $reset);
}

/**
 * Deletes a ticket_comments.
 */
function ticket_comments_delete(TicketComment $ticket_comments) {
  $ticket_comments->delete();
}

/**
 * Delete multiple ticket_comments.
 *
 * @param $pids
 *   An array of ticket_comments IDs.
 */
function ticket_comments_delete_multiple(array $ticket_comments_ids) {
  entity_get_controller('ticket_comments')->delete($ticket_comments_ids);
}

/**
 * Create a new ticket_comments object.
 */
function ticket_comments_create(array $values) {
  return new TicketComment($values);
}


/**
 * Saves a ticket_comments to the database.
 *
 * @param $ticket_comments
 *   The ticket_comments object.
 */
function ticket_comments_save(TicketComment $ticket_comments) {
  return $ticket_comments->save();
}


