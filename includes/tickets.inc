<?php

/**
 * @File ticket.inc
 * Provide function access to ticket
 */

/**
 * Fetch a ticket object.
 *
 * @param $ticket_id
 *   Integer specifying the ticket id.
 * @param $reset
 *   A boolean indicating that the internal cache should be reset.
 * @return
 *   A fully-loaded $ticket object or FALSE if it cannot be loaded.
 *
 * @see ticket_load_multiple()
 */
function ticket_load($ticket_id, $reset = FALSE) {
  $tickets = ticket_load_multiple(array($ticket_id), array(), $reset);
  return reset($tickets);
}

/**
 * Load multiple tickets based on certain conditions.
 *
 * @param $ticket_ids
 *   An array of ticket IDs.
 * @param $conditions
 *   An array of conditions to match against the {ticket} table.
 * @param $reset
 *   A boolean indicating that the internal cache should be reset.
 * @return
 *   An array of ticket objects, indexed by pid.
 *
 * @see entity_load()
 * @see ticket_load()
 */
function ticket_load_multiple($ticket_ids = array(), $conditions = array(), $reset = FALSE) {
  return entity_load('ticket', $ticket_ids, $conditions, $reset);
}

/**
 * Deletes a ticket.
 */
function ticket_delete(TicketEntity $ticket) {
  $ticket->delete();
}

/**
 * Delete multiple tickets.
 *
 * @param $pids
 *   An array of ticket IDs.
 */
function ticket_delete_multiple(array $ticket_ids) {
  entity_get_controller('ticket')->delete($ticket_ids);
}

/**
 * Create a new ticket object.
 */
function ticket_create(array $values) {
  return new TicketEntity($values);
}


/**
 * Saves a ticket to the database.
 *
 * @param $ticket
 *   The ticket object.
 */
function ticket_save(TicketEntity $ticket) {
  return $ticket->save();
}



