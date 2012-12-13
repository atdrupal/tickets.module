<?php

/**
 * @File ticket_comment.inc
 * Provide function access to ticket_comment
 */

/**
 * Fetch a ticket_comment object.
 *
 * @param $ticket_mid
 *   Integer specifying the ticket_comment id.
 * @param $reset
 *   A boolean indicating that the internal cache should be reset.
 * @return
 *   A fully-loaded $ticket_comment object or FALSE if it cannot be loaded.
 *
 * @see ticket_comment_load_multiple()
 */
function ticket_comment_load($ticket_mid, $reset = FALSE) {
  $ticket_comment = ticket_comment_load_multiple(array($ticket_mid), array(), $reset);
  return reset($ticket_comment);
}

/**
 * Load multiple ticket_comment based on certain conditions.
 *
 * @param $ticket_mids
 *   An array of ticket_comment IDs.
 * @param $conditions
 *   An array of conditions to match against the {ticket_comment} table.
 * @param $reset
 *   A boolean indicating that the internal cache should be reset.
 * @return
 *   An array of ticket_comment objects, indexed by pid.
 *
 * @see entity_load()
 * @see ticket_comment_load()
 */
function ticket_comment_load_multiple($ticket_mids = array(), $conditions = array(), $reset = FALSE) {
//  kpr($conditions);
//  kpr($ticket_mids);
  return entity_load('ticket_comment', $ticket_mids, $conditions, $reset);
}

/**
 * Deletes a ticket_comment.
 */
function ticket_comment_delete(TicketComment $ticket_comment) {
  $ticket_comment->delete();
}

/**
 * Delete multiple ticket_comment.
 *
 * @param $pids
 *   An array of ticket_comment IDs.
 */
function ticket_comment_delete_multiple(array $ticket_mids) {
  entity_get_controller('ticket_comment')->delete($ticket_mids);
}

/**
 * Create a new ticket_comment object.
 */
function ticket_comment_create(array $values) {
  return new TicketComment($values);
}


/**
 * Saves a ticket_comment to the database.
 *
 * @param $ticket_comment
 *   The ticket_comment object.
 */
function ticket_comment_save(TicketComment $ticket_comment) {
  return $ticket_comment->save();
}


