<?php

/**
 * @file
 * Example tpl file for theming a single ticket-specific theme
 *
 * Available variables:
 * - $status: The variable to theme (while only show if you tick status)
 * 
 * Helper variables:
 * - $ticket: The Ticket object this status is derived from
 */
?>

<div class="ticket-status">
  <?php print '<strong>Ticket Sample Data:</strong> ' . $ticket_sample_data = ($ticket_sample_data) ? 'Switch On' : 'Switch Off' ?>
</div>