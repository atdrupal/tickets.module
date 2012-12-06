<?php

class TicketEntity extends Entity {
  public $ticket_id;
  public $type;
  public $uid;
  public $created;
  public $changed;

  public function __construct(array $values = array(), $entityType = NULL) {
    parent::__construct($values, $entityType);

    if (!$this->created) $this->created = REQUEST_TIME;
    if (!$this->changed) $this->changed = REQUEST_TIME;
    if (!$this->uid) $this->uid = user_is_anonymous() ? 0 : $GLOBALS['user']->uid;
  }
}