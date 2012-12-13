<?php

class TicketComment extends Entity {
  public $ticket_mid;
  public $type;
  public $uid;
  public $created;
  public $changed;
  public $ticket_id;

  public function __construct(array $values = array(), $entityType = 'ticket_comment') {
    parent::__construct($values, $entityType);

    if (!$this->created) $this->created = REQUEST_TIME;
    if (!$this->changed) $this->changed = REQUEST_TIME;
    if (!$this->uid) $this->uid = user_is_anonymous() ? 0 : $GLOBALS['user']->uid;
  }
  protected function defaultUri() {
      return array('path' => 'ticket-comments/' . $this->$ticket_mid);
  }
  
  /**
   * Returns the user owning this ticket comments.
   */
  public function user() {
    return user_load($this->uid);
  }
  /**
   * Returns the user owning this ticket comments.
   */
  public function ticket() {
    return ticket_load($this->ticket_id);
  }
}