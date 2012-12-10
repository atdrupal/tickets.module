<?php

class TicketComment extends Entity {
  public $ticket_cid;
  public $type;
  public $uid;
  public $created;
  public $changed;
  public $ticket_id;

  public function __construct(array $values = array(), $entityType = 'ticket_comments') {
    parent::__construct($values, $entityType);

    if (!$this->created) $this->created = REQUEST_TIME;
    if (!$this->changed) $this->changed = REQUEST_TIME;
    if (!$this->uid) $this->uid = user_is_anonymous() ? 0 : $GLOBALS['user']->uid;
  }
  protected function defaultUri() {
      return array('path' => 'ticket-comments/' . $this->ticket_cid);
  }
}